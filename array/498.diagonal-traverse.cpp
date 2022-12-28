/*
 * @lc app=leetcode id=498 lang=cpp
 *
 * [498] Diagonal Traverse
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
    vector<int> reverseVector(vector<int>& a) {
        for (int i = 0; i < a.size() / 2; ++i) {
            int t = a[i];
            a[i] = a[a.size() - 1 - i];
            a[a.size() - 1 - i] = t;
        }
        return a;
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans;
        vector<int> cur;
        for (int i = 0; i < m + n - 1; ++i) {
            int row, col;
            row = i < n ? 0 : i - n + 1;
            col = i < n ? i : n - 1;
            cur.clear();
            while (row < m && col >= 0) {
                cur.push_back(mat[row][col]);
                row++;
                col--;
            }
            if (i % 2 == 0) {
                cur = reverseVector(cur);
            }
            for (int k = 0; k < cur.size(); ++k) {
                ans.push_back(cur[k]);
            }
        }

        return ans;
    }
};
// @lc code=end
