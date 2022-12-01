/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[1][1] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (obstacleGrid[i - 1][j - 1] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                if (i == 1) {
                    dp[i][j] += dp[i][j - 1];
                } else if (j == 1) {
                    dp[i][j] += dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end
