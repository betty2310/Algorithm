/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
   public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int res = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for (int i = 0; i < g.size(); ++i) {
            for (int j = 0; j < s.size(); ++j) {
                if (g[i] <= s[j]) {
                    ++res;
                    s.erase(s.begin() + j);
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end
