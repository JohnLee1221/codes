#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
  std::unordered_map<int, int> hashtable;
  for (int i = 0; i < nums.size(); ++i) {
    auto it = hashtable.find(target - nums[i]);
    if (it != hashtable.end()) {
      std::cout << it->first << std::endl;
      std::cout << it->second << std::endl;
      return {it->second, i};
    }
    hashtable[nums[i]] = i;
  }
  return {};
}

int main() {
  std::vector<int> test{2,7,11,15};
  int target_num = 18;
  std::vector<int> sum = twoSum(test,target_num);
  for (auto ele : sum) {
    std::cout << ele << std::endl;
  }
  return 0;
}