#include <iostream>
#include <vector>

// #include "matplotlibcpp.h"

// namespace plt = matplotlibcpp;


class PIDController {
public:
    PIDController(double kp, double ki, double kd)
        : kp_(kp), ki_(ki), kd_(kd), integral_(0), previous_error_(0) {}

    double Control(double target_value, double current_value, double dt) {
        double error = target_value - current_value;

        integral_ += error * dt;
        double derivative = (error - previous_error_) / dt;
        std::cout << derivative << std::endl;

        double output = kp_ * error + ki_ * integral_ + kd_ * derivative;

        previous_error_ = error;

        return output;
    }

private:
    double kp_;
    double ki_;
    double kd_;
    double integral_;
    double previous_error_;
};

int main() {
    double kp = 10.0;
    double ki = 10.0;
    double kd = 0.1;

    PIDController pid(kp, ki, kd);

    double target_value = 50.0;
    double current_value = 0.0;
    double dt = 0.01;
    double time = 0.0;

    std::vector<double> current_values;
    std::vector<double> output_vec;
    std::vector<double> points;

    for (int i = 0; i < 1000; ++i) {
        double control_output = pid.Control(target_value, current_value, dt);
        current_value += control_output * dt;

        points.push_back(target_value);
        current_values.push_back(current_value);
        output_vec.push_back(control_output);

        // std::cout << "Time: " << time << " Setpoint: " << setpoint << " Current Value: " << current_value
        //           << " Control Output: " << control_output << std::endl;

    //   if (i % 10 == 0) {
      //   plt::clf();										// 清空之前的plot数据
      //   plt::named_plot("target", points);			// 绘制一个sin(x)函数
      //   plt::named_plot("current_value", current_values);			// 绘制一个log(x)函数
      //   plt::named_plot("control_output", output_vec);			// 绘制一个log(x)函数
        
      //   std::map<std::string, std::string> style;
      //   style["color"] = "red";
      //   style["marker"] = "o";
      //   style["markersize"] = "5";
      //   plt::named_plot("current_value", current_values, style);			// 绘制一个log(x)函数
      //   plt::named_plot("control_output", output_vec, "og");			// 绘制一个log(x)函数
                
      //   plt::xlim(0, 1000);							// 设置x轴的范围
      //   plt::ylim(-20, 100);							// 设置x轴的范围
      //   plt::title("Sample figure");

      //   plt::legend();
      //   plt::pause(0.01);								// 图片显示时间，与legend()配合使用
	    // }

        time += dt;
    }

    // plt::show();

    return 0;
}
