#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <cmath>

constexpr auto kFileDir = "/home/lzh/Documents/codes/planning/data/routing_path.csv";

std::vector<std::string> StringParse(const std::string& message) {
  std::istringstream ss(message);
  std::vector<std::string> segment;
  std::string token;
  while (std::getline(ss, token, ',')) {
    segment.push_back(token);
  }
  return segment;
}

void ReadFile(const std::string& filename) {
  std::vector<double> messages;
  if (!messages.empty()) {
    messages.clear();
  }

  std::ifstream file_in(filename.c_str());
  if (!file_in.is_open()) {
    std::cout << "Can not open xxx file: " << filename << std::endl;
    std::exit(1);
  }

  std::string line;
  // 跳过头行
  getline(file_in, line);

  while (true) {
    getline(file_in, line);
    if (line == "") {
      break;
    }
    auto tokens = StringParse(line);
    // 验证数据的完整性
    if (tokens.size() < 2) {
      std::cout << "parse line failed; the data dimension does not match." << line << std::endl;
      continue;
    }

    std::cout << std::stod(tokens[0]) << "\t"
              << std::stod(tokens[1]) << std::endl;
  }

  file_in.close();
}

int main() {
  ReadFile(kFileDir);

  return 0;
}
