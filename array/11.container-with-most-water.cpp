/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
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
    int maxArea(vector<int>& height) {
        int n = height.size();
        if (n == 2) return min(height[0], height[1]);
        int ans = 0;
        int left = 0, right = n - 1;
        while (left < right) {
            int h = min(height[left], height[right]);
            ans = max(ans, h * (right - left));
            while (left < right && height[left] <= h) left++;
            while (left < right && height[right] <= h) right--;
        }
        return ans;
    }
};
// @lc code=end
