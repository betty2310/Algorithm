/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
#include <algorithm>
#include <cctype>
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
    bool isPalindrome(string s) {
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = tolower(s[i]);
            } else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
                continue;
            } else {
                s.erase(i, 1);
                --i;
            }
        }
        if (s.length() <= 1) return true;
        bool fl = true;
        int n = s.length();
        for (int i = 0; i < n / 2; ++i) {
            if (s[i] != s[n - 1 - i]) {
                fl = false;
                break;
            }
        }
        return fl;
    }
};
// @lc code=end
