#include <iostream>
#include <fstream>
#include <iomanip>

struct Data {
  int number;
  std::string str;
};

class Data2Log {
 public:
  Data2Log() : file_name_(GetTimeStamp() + ".log") {
    Init();
  }
  Data2Log(const std::string& name) : file_name_(name + ".log") {
    Init();
  }

  void operator()(const Data& data) {
    if (op_file_.is_open()) {
      // 设置输出数据
      op_file_ << std::setprecision(5) << data.number << "\t" << data.str << std::endl;
    } else {
      std::cout << "Open file is failure" << std::endl;
    }
  }

 private:
  void Init() {
    op_file_.open(file_name_.c_str());
    // 设置log文件抬头
    op_file_ << "number" << "\t" << "string" << std::endl;
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
  std::string file_name_;
  std::ofstream op_file_;
};


int main(int argc, char **argv) {
  Data test_data;
  Data2Log log_file("log_class");
  for (size_t i = 1; i < 100; ++i) {
    test_data.number = i;
    test_data.str = "test-" + std::to_string(i);
    log_file(test_data);
  }

  return 0;
}