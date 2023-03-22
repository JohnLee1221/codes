/******************************************************************************
 * 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 * 示例 1：
 * 输入：nums = [1,5,11,5]
 * 输出：true
 * 解释：数组可以分割成 [1, 5, 5] 和 [11] 。
 * 
 * 示例 2：
 * 输入：nums = [1,2,3,5]
 * 输出：false
 * 解释：数组不能分割成两个元素和相等的子集。
********************************************************************************/ 

#include <iostream>
#include <vector>

#if 0
//  二维数组
class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
      int sum = 0;
      for (auto value : nums) {
        sum += value;
      }
      if (sum % 2 != 0) {
        return false;
      }
      int target = sum / 2;
      int size = nums.size();
      std::vector<std::vector<int>> dp(size + 1, std::vector<int>(target + 1, 0));
      for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= target; j++) {
          if (j < nums[i - 1]) {
            dp[i][j] = dp[i - 1][j];
          } else {
            dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - nums[i - 1]] + nums[i - 1]);
            std::cout << dp[i][j] << std::endl;
            if (dp[i][j] == target) {
              return true;
            }
          }
        }
      }
      return false;
    }
};
#endif

#if 1
//  一维数组
class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
      int sum = 0;
      for (auto value : nums) {
        sum += value;
      }
      if (sum / 2 == 1) {
        return false;
      }
      int target = sum / 2;
      std::vector<int> dp(nums.size() + 1, 0);
      for (int i = 0; i <= nums.size(); i++) {
        for (int j = target; j >= 0; j--) {
          if (j > nums[j - 1]) {
            dp[j] = std::max(dp[j], dp[j - nums[j - 1]] + nums[j - 1]);
          }
          if (dp[j] == target) {
            return true;
          }
        }
      }
      return false;
    }
};
#endif

int main() {
  Solution s;
  std::vector<int> v = {3,7,11,5,4,6};
  if (s.canPartition(v)) {
    std::cout << "Success" << std::endl;
  } else {
    std::cout << "False" << std::endl;
  }

  return 0;
}