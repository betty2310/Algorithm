/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
#include <iostream>
using namespace std;
class Solution {
   public:
    int uniquePaths(int m, int n) {
        int grid[101][101] = {0};
        grid[1][1] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == 1) {
                    grid[i][j] += grid[i][j - 1];
                } else if (j == 1) {
                    grid[i][j] += grid[i - 1][j];
                } else {
                    grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
                }
            }
        }
        return grid[m][n];
    }
};
// @lc code=end
