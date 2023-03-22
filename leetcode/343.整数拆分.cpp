#include <iostream>
#include <vector>

class Solution {
public:
    int integerBreak(int n) {
      std::vector<int> dp(n+1,0);
      dp[2] = 1;
      dp[3] = 2;
      auto max = [](int a, int b, int c) {
        int temp = a > b ? a : b;
        return temp > c ? temp : c;
      };
      for (int i = 3; i <= n; i++) {
        for (int j = 1; j <= i - 1; j++) {
          dp[i] = max((i - j) * j, dp[i - j] * j, dp[i]);
        }
      }
      std::cout << dp.size() << std::endl;
      for (auto value : dp) {
        std::cout << value << std::endl;
      }

      return dp[n];
    }
};

int main() {
  Solution s;
  std::cout << s.integerBreak(10) << std::endl;

  return 0;
}

