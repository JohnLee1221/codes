#include <iostream>
#include <vector>

class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
      int size = cost.size();
      std::vector<int> dp(size, 0);
      dp[0] = cost[0];
      dp[1] = cost[1];
      for (int i = 2; i < size; i++) {
        dp[i] = std::min(dp[i - 2] + cost[i], dp[i - 1] + cost[i]);
      }
      return dp[size - 1];
    }
};

int main() {
  Solution solution;
  std::vector<int> v = {1,100,1,1,1,100,1,1,100,1};
  std::cout << solution.minCostClimbingStairs(v) << std::endl;

  return 0;
}