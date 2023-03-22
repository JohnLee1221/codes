#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <assert.h>

struct Player {
  std::string name;
  int socre;
  std::deque<int> socre_deq{};
};

class SocringSystem {
 public:
  SocringSystem() = default;
  void Init(int num);
  void Run();
  void PrintInfo();

 private:
  int GetAvg(std::deque<int>);
  void Socring(std::deque<int>&);
  std::vector<Player> player_vec_;
};

void SocringSystem::Init(int num) {
  player_vec_.resize(num);
  std::string idx = "ABCDEFG";
  if (num > 7) {
    std::cout << "Too much players." << std::endl;
    assert(false);
  } else {
    int i = 0;
    for (std::vector<Player>::iterator iter = player_vec_.begin();
         iter != player_vec_.end(); iter++) {
      std::string player = "Player ";
      iter->name = player += idx[i];
      i++;
    }
  }
}

void SocringSystem::Socring(std::deque<int>& q) {
  for (int i = 0; i < 10; i++) {
    int socre_tmp = rand() % 41 + 60;
    q.push_back(socre_tmp);
  }
}

int SocringSystem::GetAvg(std::deque<int> q) {
  std::sort(q.begin(),q.end());
  q.pop_front();
  q.pop_back();
  int value = 0;
  for (auto ele : q) {
    value += ele;
  }
  return value / q.size();
}

void SocringSystem::Run() {
  for (std::vector<Player>::iterator iter = player_vec_.begin();
       iter != player_vec_.end(); iter++) {
    Socring(iter->socre_deq);
    iter->socre = GetAvg(iter->socre_deq);
  } 
}

void SocringSystem::PrintInfo() {
  for (auto ele : player_vec_) {
    std::cout << ele.name << "  avg: " << ele.socre << std::endl;
    std::cout << "score is : ";
    for (auto num : ele.socre_deq) {
      std::cout << num << " ";
    }
    std::cout << "\n";
  }
}

int main() {
  srand((unsigned int)time(NULL));
  SocringSystem s;
  s.Init(6);
  s.Run();
  s.PrintInfo();

  return 0;
}