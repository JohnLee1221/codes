#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
      int m = nums.size();
      std::vector<int> dp(m, 1);
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < i; j++) {
          if (nums[j] < nums[i]) {
            dp[i] = std::max(dp[j] + 1, dp[i]);
          }
        }
      }
      for (auto element : dp) {
        std::cout << element << std::endl;
      }
      return *max_element(dp.begin(), dp.end());
    }
};

int main() {
  Solution s;
  std::vector<int> v = {10,9,2,5,3,7,101,18};
  std::cout << s.lengthOfLIS(v) << std::endl;

  return 0;
}