/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = n - 1, up = 0, down = m - 1;
        while (ans.size() < m * n) {
            for (int i = left; i <= right && ans.size() < m * n; ++i) {
                ans.push_back(matrix[up][i]);
            }
            for (int i = up + 1; i <= down && ans.size() < m * n; ++i) {
                ans.push_back(matrix[i][right]);
            }
            for (int i = right - 1; i >= left && ans.size() < m * n; --i) {
                ans.push_back(matrix[down][i]);
            }
            for (int i = down - 1; i >= up + 1 && ans.size() < m * n; --i) {
                ans.push_back(matrix[i][left]);
            }
            left++;
            right--;
            up++;
            down--;
        }
        return ans;
    }
};
// @lc code=end
