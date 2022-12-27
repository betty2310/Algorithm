/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.empty()) return {};
        if (nums.size() < 4) return {};

        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            int target_3 = target - nums[i];
            for (int j = i + 1; j < n; ++j) {
                int target_2 = target_3 - nums[j];
                int low = j + 1;
                int high = n - 1;
                while (low < high) {
                    int sum = nums[low] + nums[high];
                    if (sum < target_2) {
                        low++;
                    } else if (sum > target_2) {
                        high--;
                    } else {
                        res.push_back({nums[i], nums[j], nums[low], nums[high]});
                        int last_low = nums[low];
                        int last_high = nums[high];
                        while (low < high && nums[low] == last_low) low++;
                        while (low < high && nums[high] == last_high) high--;
                    }
                }
                while (j + 1 < n && nums[j + 1] == nums[j]) j++;
            }
            while (i + 1 < n && nums[i + 1] == nums[i]) i++;
        }
        return res;
    }
};
// @lc code=end
