#include "transform.h"

const std::string kFILE_PATH = "../data/short_camera_extrinsics.yaml";

int main() {
  TransForms transform;
  transform.ParseYamlFile(kFILE_PATH);
  return 0;
}