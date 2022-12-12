/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <semaphore>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
   public:
    bool isMatch(string s, string p) {
        int sn = s.length();
        int pn = p.length();
        vector<vector<bool>> dp(sn + 1, vector<bool>(pn + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= sn; ++i) {
            for (int j = 1; j <= pn; ++j) {
                if (p[j - 1] != '*') {
                    dp[i][j] = i && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                } else {
                    dp[i][j] = dp[i][j - 2] ||
                               (i && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                }
            }
        }
        return dp[sn][pn];
    }
};
// @lc code=end
