/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            int j = 0;
            for (j = 0; j < strs[i].size(); ++j) {
                if (ans[j] != strs[i][j]) break;
            }
            ans = ans.substr(0, j);
            if (ans == "") return "";
        }

        return ans;
    }
};
// @lc code=end
