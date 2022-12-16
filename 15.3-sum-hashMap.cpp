/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
//
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Sorted Array
        if (nums.size() < 3) {           // Base case 1
            return {};
        }
        if (nums[0] > 0) {  // Base case 2
            return {};
        }
        unordered_map<int, int> hashMap;
        for (int i = 0; i < nums.size(); ++i) {
            hashMap[nums[i]] = i;
        }

        vector<vector<int>> answer;
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (nums[i] > 0) break;
            for (int j = i + 1; j < nums.size() - 1; ++j) {
                int rest = (nums[i] + nums[j]) * -1;
                if (hashMap.count(rest) && hashMap.find(rest)->second > j) {
                    answer.push_back(rest, nums[i], nums[j]);
                }
                j = hashMap.find(nums[j])->second;
            }
            i = hashMap.find(nums[i])->second;
        }

        return answer;
    }
};
// @lc code=end
