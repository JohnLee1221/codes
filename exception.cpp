#include <iostream>
#include <fstream>
// #include <exception>

class FileReading {
 public:
  FileReading(const std::string& file_name) {
    file_.open(file_name);
    if (!file_.is_open()) {
      throw std::runtime_error("Failed to open file: " + file_name);
    }
    std::cout << "FileReading constructed successfully" << std::endl;
  }

  void ReadAndPrint() {
    std::string line;
    while (std::getline(file_, line)) {
      std::cout << line << std::endl;
    }
  }

  ~FileReading() {
    if (file_.is_open()) {
      file_.close();
      std::cout << "FileReading distructed successfully" << std::endl;
    }
  }

 private:
  std::ifstream file_;
};

void Adapter(const std::string& name) {
  try {
    FileReading reader(name + ".txt");
    reader.ReadAndPrint();
  } catch (const std::exception& err) {
    std::cerr << err.what() << std::endl;
  }
}
  
int main() {
  Adapter("example"); 
  // Adapter("lalala"); 

  return 0;
}