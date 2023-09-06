#include <iostream>
#include "tinyxml.h"

int main() {
    TiXmlDocument doc("/home/lzh/tmp/example.xml");
    bool load_success = doc.LoadFile();
    if (!load_success) {
        std::cout << "Failed to load xml file." << std::endl;
        return 1;
    }

    TiXmlElement* root = doc.RootElement();

    // 解析 Field 节点
    TiXmlElement* field = root->FirstChildElement("Field");
    std::string field_id = field->Attribute("id");
    std::string field_date = field->Attribute("date");
    double field_area = atof(field->Attribute("area"));
    std::cout << field_id << "\t" << field_date << "\t" << field_area << std::endl;

    // 解析 Polygon 节点
    TiXmlElement* polygon = field->FirstChildElement("geometry")->FirstChildElement("Polygon");
    std::string polygon_srsName = polygon->Attribute("srsName");
    TiXmlElement* outerBoundaryIs = polygon->FirstChildElement("outerBoundaryIs");
    TiXmlElement* linearRing = outerBoundaryIs->FirstChildElement("LinearRing");
    std::string coordinates_str = linearRing->FirstChild()->ValueStr();
    std::istringstream coordinates_stream(coordinates_str);
    std::string coordinate_pair;
    while (std::getline(coordinates_stream, coordinate_pair, ' ')) {
        std::istringstream coordinate_stream(coordinate_pair);
        std::string lon_str, lat_str;
        std::getline(coordinate_stream, lon_str, ',');
        std::getline(coordinate_stream, lat_str, ',');
        double lon = atof(lon_str.c_str());
        double lat = atof(lat_str.c_str());
        std::cout << "Coordinate: (" << lon << ", " << lat << ")" << std::endl;
    }

    // 解析 Edge 节点
    TiXmlElement* edge = root->FirstChildElement("Edge");
    std::string edge_id = edge->Attribute("id");
    std::string edge_date = edge->Attribute("date");
    double edge_maxstripwidth = atof(edge->Attribute("maxstripwidth"));
    double edge_minstripwidth = atof(edge->Attribute("minstripwidth"));
    int edge_include = atoi(edge->Attribute("include"));
    int edge_preference = atoi(edge->Attribute("preference"));
    int edge_striptype = atoi(edge->Attribute("striptype"));
    TiXmlElement* lineString = edge->FirstChildElement("geometry")->FirstChildElement("LineString");
    std::string lineString_srsName = lineString->Attribute("srsName");
    std::string lineString_coordinates_str = lineString->FirstChild()->ValueStr();
    std::istringstream lineString_coordinates_stream(lineString_coordinates_str);
    while (std::getline(lineString_coordinates_stream, coordinate_pair, ' ')) {
        std::istringstream coordinate_stream(coordinate_pair);
        std::string lon_str, lat_str;
        std::getline(coordinate_stream, lon_str, ',');
        std::getline(coordinate_stream, lat_str, ',');
        double lon = atof(lon_str.c_str());
        double lat = atof(lat_str.c_str());
        std::cout << "Coordinate: (" << lon << ", " << lat << ")" << std::endl;
    }

    return 0;
}
