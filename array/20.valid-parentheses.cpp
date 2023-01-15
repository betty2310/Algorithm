/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
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
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else {
                char top = st.top();
                switch (s[i]) {
                    case ')':
                        if (top == '(')
                            st.pop();
                        else
                            return false;
                        break;

                    case ']':
                        if (top == '[')
                            st.pop();
                        else
                            return false;
                        break;
                    case '}':
                        if (top == '{')
                            st.pop();
                        else
                            return false;
                        break;
                    default:
                        break;
                }
            }
        }
        if (st.empty()) return true;
        return false;
    }
};
// @lc code=end
