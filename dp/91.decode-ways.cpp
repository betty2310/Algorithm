/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start

#include <string>
using namespace std;

class Solution {
   public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') return 0;
        if (n == 1) return 1;
        int dp[101] = {0};
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] != '0') dp[i] += dp[i - 1];
            if (i >= 2) {
                int x = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
                if (10 <= x && x <= 26) dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};
// @lc code=end
