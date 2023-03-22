#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
      int m = triangle.size();
      std::vector<std::vector<int>> dp(m, std::vector<int>(m, 0));
      dp[0][0] = triangle[0][0];
      for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i - 1][0] + triangle[i][0];
        dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
      }
      for (int i = 1; i < m; i++) {
        for (int j = 1; j < i; j++) {
          dp[i][j] = std::min(dp[i - 1][j - 1] + triangle[i][j], dp[i - 1][j] + triangle[i][j]);
        }
      }
      return *min_element(dp[m - 1].begin(), dp[m - 1].end());
    }
};

int main() {
  Solution s;
  std::vector<std::vector<int>> test{{2},{3,4},{6,5,7},{4,1,8,3}};
  std::cout << s.minimumTotal(test) << std::endl;

  return 0;
}