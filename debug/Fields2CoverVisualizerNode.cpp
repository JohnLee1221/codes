//=============================================================================
//    Copyright (C) 2021-2022 Wageningen University - All Rights Reserved
//                     Author: Gonzalo Mier
//                        BSD-3 License
//=============================================================================


#include "Fields2CoverVisualizerNode.h"
#include "fields2cover/route_planning/loop_order.h"
#include "ros/conversor.h"

#include <fstream>
#include <iostream>
#include <dynamic_reconfigure/server.h>
#include <fields2cover_ros/F2CConfig.h>


using namespace std;


namespace fields2cover_ros {
    
    void VisualizerNode::init_VisualizerNode() {
      field_polygon_publisher_ = public_node_handle_.advertise<geometry_msgs::PolygonStamped>("/field/border", 1, true);
      field_no_headlands_publisher_ = public_node_handle_.advertise<geometry_msgs::PolygonStamped>("/field/no_headlands", 1, true);
      field_gps_publisher_ = public_node_handle_.advertise<sensor_msgs::NavSatFix>("/gps/fix", 1, true);
      field_swaths_publisher_ = public_node_handle_.advertise<visualization_msgs::Marker>("/field/swaths", 1, true);


      std::string field_file;
      private_node_handle_.getParam(
          "field_file", field_file);

      f2c::Parser::importGml(field_file, fields_);
      // f2c::Transform::transform(fields_[0], "EPSG:28992");
      // 上海地区的EPSG码 4529
      // f2c::Transform::transform(fields_[0], "EPSG:4529");
      robot_.cruise_speed = 2.0;
      robot_.setMinRadius(2.0);
      double headland_width = 3.0*robot_.op_width;
    }

    void VisualizerNode::publish_topics(void) {
      auto gps = transf_.getRefPointInGPS(fields_[0]);

      //
      F2CCells cells = fields_[0].field;
      size_t cs_size = cells.size();
      for (size_t i = 0; i < cs_size; ++i) {
          F2CCell cell = cells.getCell(i);
          size_t c_size = cell.size();
          for (size_t j = 0; j < c_size; ++j) {
              F2CLinearRing linear_ring;
              linear_ring = cell.getGeometry(i);
              size_t lr_size = linear_ring.size();
              for (size_t k = 0; k < lr_size; ++k) {
                  F2CPoint point;
                  point = linear_ring.getGeometry(k);
                  std::cout << point.getX() << "\t" << point.getY() << "\t" << point.getZ() << std::endl; 
              }
          }
      }

      gps_.longitude = gps.getX();
      gps_.latitude = gps.getY();
      gps_.altitude = gps.getZ();
      gps_.header.stamp = ros::Time::now();
      gps_.header.frame_id = "base_link";
      field_gps_publisher_.publish(gps_);

      auto f = fields_[0].field.clone();
      f2c::hg::ConstHL hl_gen_;
      F2CCell no_headlands = hl_gen_.generateHeadlands(f, optim_.headland_width).getGeometry(0);

      geometry_msgs::PolygonStamped polygon_st;
      polygon_st.header.stamp = ros::Time::now();
      polygon_st.header.frame_id = "base_link";
      conversor::ROS::to(f.getCellBorder(0), polygon_st.polygon);
      field_polygon_publisher_.publish(polygon_st);
      polygon_st.polygon.points.clear();
      
      geometry_msgs::PolygonStamped polygon_st2;
      polygon_st2.header.stamp = ros::Time::now();
      polygon_st2.header.frame_id = "base_link";
      conversor::ROS::to(no_headlands.getGeometry(0), polygon_st2.polygon);
      field_no_headlands_publisher_.publish(polygon_st2);
      polygon_st2.polygon.points.clear();



      F2CSwaths swaths;
      f2c::sg::BruteForce swath_gen_;
      if (automatic_angle_) {
        switch (sg_objective_) {
          case 0 : {
            f2c::obj::SwathLength obj;
            swaths = swath_gen_.generateBestSwaths(obj, robot_.op_width, no_headlands);
            break;
	  }
          case 1 : {
            f2c::obj::NSwath obj;
            swaths = swath_gen_.generateBestSwaths(obj, robot_.op_width, no_headlands);
            break;
	  }
          case 2 : {
            f2c::obj::FieldCoverage obj;
            swaths = swath_gen_.generateBestSwaths(obj, robot_.op_width, no_headlands);
            break;
	  }
	}
      }
      else {
        swaths = swath_gen_.generateSwaths(optim_.best_angle,
            robot_.op_width, no_headlands);
      }

      F2CSwaths route;
      switch (opt_route_type_) {
        case 0 : {
          f2c::rp::BoustrophedonOrder swath_sorter;
          route = swath_sorter.genSortedSwaths(swaths);
          break;
        }
        case 1 : {
          f2c::rp::SnakeOrder swath_sorter;
          route = swath_sorter.genSortedSwaths(swaths);
          break;
        }
        case 2 : {
          f2c::rp::SpiralOrder swath_sorter(6);
          route = swath_sorter.genSortedSwaths(swaths);
          break;
        }
        case 3 : {
          // f2c::rp::SpiralOrder swath_sorter(4);
          f2c::rp::LoopOrder swath_sorter;
          route = swath_sorter.genSortedSwaths(swaths);
          break;
        }
      }
      size_t size;
      // 作业道路个数, 即: route.data的size
      size = route.size();
      std::cout << "=====> route size: " << size << std::endl;

      for (auto iter = route.begin(); iter != route.end(); ++iter) {
        auto line_string = iter->getPath();
        size_t tmp_size = line_string.size();
        std::cout << "------------" << std::endl;
        for (size_t i = 0; i < tmp_size; ++i) {
          std::cout << "    Point: " << line_string.getX(i) << "\t" << line_string.getY(i) << "\t" << line_string.getZ(i) << std::endl;
        }
      }

      F2CPath path;
      f2c::pp::PathPlanning path_planner;

      switch(opt_turn_type_) {
        case 0 : {
          f2c::pp::DubinsCurves turn;
          path = path_planner.searchBestPath(robot_, route, turn);
          break;
        }
        case 1 : {
          f2c::pp::DubinsCurvesCC turn;
          path = path_planner.searchBestPath(robot_, route, turn);
          break;
        }
        case 2 : {
          f2c::pp::ReedsSheppCurves turn;
          path = path_planner.searchBestPath(robot_, route, turn);
          break;
        }
        case 3 : {
          f2c::pp::ReedsSheppCurvesHC turn;
          path = path_planner.searchBestPath(robot_, route, turn);
          break;
        }
      }


      visualization_msgs::Marker marker_swaths;
      marker_swaths.header.frame_id = "base_link";
      marker_swaths.header.stamp = ros::Time::now();
      marker_swaths.action = visualization_msgs::Marker::ADD;
      marker_swaths.pose.orientation.w = 1.0;
      marker_swaths.type = visualization_msgs::Marker::LINE_STRIP;
      marker_swaths.scale.x = 1.0;
      marker_swaths.scale.y = 1.0;
      marker_swaths.scale.z = 1.0;
      marker_swaths.color.g = 0.5;
      marker_swaths.color.a = 1.0;
      geometry_msgs::Point ros_p;

      // 输出log文件的仿函数
      class Data2Log {
        public:
          Data2Log() : file_name_(GetTimeStamp() + ".csv") {
            Init();
          }
          Data2Log(std::string file_name) : file_name_(file_name + ".csv") {
            Init();
          }

          void operator()(const f2c::types::PathState& state) {
            if (op_file_.is_open()) {
              op_file_ << std::setprecision(10) << state.point.getX() << "," \
                                                << state.point.getY() << "," \
                                                << state.point.getZ() << "," \
                                                << default_vale + 0.5 << "," \
                                                << default_vale << "," \
                                                << default_vale << "," \
                                                << default_vale << "," \
                                                << default_vale << "," \
                                                << state.angle << "," \
                                                << default_vale << "," \
                                                << default_vale << "," \
                                                << default_vale << "," \
                                                << default_vale << "," \
                                                << default_vale << std::endl;
            } else {
              std::cout << "Open file is failure" << std::endl;
            }
          }

        private:
          void Init() {
            op_file_.open(file_name_.c_str());
            // 设置log文件抬头
            // op_file_ << "x,y,z,heading" << std::endl;
            op_file_ << "x,y,z,speed,acceleration,curvature,curvature_change_rate,time,theta,gear,s,throttle,brake,steering" << std::endl;
          }
          std::string GetTimeStamp() {
            time_t current_time = time(nullptr);
            char current_time_char[256];
            strftime(current_time_char, sizeof(current_time_char), "%Y%m%d%H%M%S",	//年月日时分秒
                    localtime(&current_time));
            std::string current_time_str = current_time_char;
            return current_time_str;
          }
        private:
          int default_vale = 0;
          std::string file_name_;
          std::ofstream op_file_;
      } log_file("planning_trajecotry");

      size_t path_size = path.states.size();
      F2CPath output_path;
      // 离散精度0.1m
      const double discretization = 0.1;
      for (int i = 0; i < path_size - 1; ++i) {
        double points_x_delta = path.states[i + 1].point.getX() - path.states[i].point.getX();
        double points_y_delta = path.states[i + 1].point.getY() - path.states[i].point.getY();
        double points_delta = std::sqrt(points_x_delta * points_x_delta + points_y_delta * points_y_delta);
        if (points_delta == 0) {
          continue;
        }else if (points_delta > discretization) {
          int num = points_delta / discretization;
          double precision_x = points_x_delta / num;
          double precision_y = points_y_delta / num;
          for (int j = 0; j < num; ++j) {
            F2CPathState path_state;
            path_state.point.setX(path.states[i].point.getX() + j * precision_x);
            path_state.point.setY(path.states[i].point.getY() + j * precision_y);
            path_state.angle = path.states[i].angle;
            output_path.states.emplace_back(path_state);
          }
        } else {
          output_path.states.emplace_back(path.states[i]);
        }
      }

      for (auto&& s : output_path.states) {
        log_file(s);
	      conversor::ROS::to(s.point, ros_p);
        marker_swaths.points.push_back(ros_p);
      }
      field_swaths_publisher_.publish(marker_swaths);
    }

    void VisualizerNode::rqt_callback(fields2cover_ros::F2CConfig &config, uint32_t level) {
      robot_.op_width = config.op_width;
      robot_.setMinRadius(config.turn_radius);
      optim_.best_angle = config.swath_angle;
      optim_.headland_width = config.headland_width;
      automatic_angle_ = config.automatic_angle;
      sg_objective_ = config.sg_objective;
      opt_turn_type_ = config.turn_type;
      opt_route_type_ = config.route_type;
      publish_topics();
    }
}


