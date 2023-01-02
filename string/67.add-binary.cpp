/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
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
    string addBinary(string a, string b) {
        int n = a.length() - 1, m = b.length() - 1;
        string res = "";
        int carry = 0;
        while (n >= 0 || m >= 0 || carry != 0) {
            if (n >= 0) {
                carry += a[n] == '0' ? 0 : 1;
                n--;
            }
            if (m >= 0) {
                carry += b[m] == '0' ? 0 : 1;
                m--;
            }
            res = (carry % 2 == 0 ? '0' : '1') + res;
            carry /= 2;
        }
        return res;
    }
};
// @lc code=end
