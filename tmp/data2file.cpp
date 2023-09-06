#include <iostream>
#include <fstream>
#include <time.h>
#include <thread>
#include <chrono>

static int count = 0;

struct Data {
  int num;
  std::string identifer;
};

std::string GetTimeStamp() {
  time_t current_time = time(nullptr);
  char current_time_char[256];
  strftime(current_time_char, sizeof(current_time_char), "%Y%m%d%H%M%S",
           localtime(&current_time));
  std::string current_time_str = current_time_char;
  return current_time_str;
}

Data Assign() {
  Data data;
  data.num = count;
  data.identifer = "test";
  count++;
  return data;
}

int main(int argc, char **argv) {
  std::string timestamp = GetTimeStamp();
  std::string file_name = "data" + timestamp + ".csv";
  std::ofstream fout;
  fout.open(file_name.c_str());
  fout << "num,id" << std::endl;
  while (true) {
    Data test_data = Assign();
    fout << test_data.num << "," << test_data.identifer << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }
  fout.close();

  return 0;
}