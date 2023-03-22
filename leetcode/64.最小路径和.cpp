#include <iostream>
#include <vector>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();
      std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
      dp[0][0] = grid[0][0];
      for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
      }
      for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
      }
      for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
          dp[i][j] = std::min(dp[i - 1][j] + grid[i][j], dp[i][j - 1] + grid[i][j]);
        }
      }
      return dp[m - 1][n - 1];
    }
};

int main() {
  Solution s;
  std::vector<std::vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
  std::cout << s.minPathSum(grid) << std::endl;

  return 0;
}