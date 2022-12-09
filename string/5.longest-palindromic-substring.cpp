/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
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
    string longestPalindrome(string s) {
        int i = 0;
        int left = 0, right = 0;
        int min_left = 0, max_right = 1;
        while (i < s.length()) {
            int j = i;
            while (s[i] == s[j + 1]) {
                ++j;
            }
            left = i;
            right = j;
            // cout << left << " " << right << "\n";
            while (left > 0 && right < s.length() - 1 && s[left - 1] == s[right + 1]) {
                // cout << s[left] << " " << s[right] << "\n";
                left--;
                right++;
            }
            // cout << left << " " << right << "\n";
            int new_right = right - left + 1;
            if (new_right > max_right) {
                max_right = new_right;
                min_left = left;
            }
            i = j + 1;
        }
        return s.substr(min_left, max_right);
    }
};
// @lc code=end
