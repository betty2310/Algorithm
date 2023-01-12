/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for (auto x : nums1) nums2.push_back(x);
        for (auto x : nums2) cout << x << " ";
        if (nums2.size() % 2 == 0)
            return nums2[nums2.size() / 2 - 1] + nums2[nums2.size() / 2];
        else
            return nums2[nums2.size() / 2];
    }
};
// @lc code=end
