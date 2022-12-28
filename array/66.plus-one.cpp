/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int note = 0;
        digits[n - 1] += 1;
        if (digits[n - 1] == 10) {
            digits[n - 1] = 0;
            note = 1;
        }
        for (int i = n - 2; i >= 0; --i) {
            digits[i] = digits[i] + note;
            if (digits[i] == 10) {
                digits[i] = 0;
                note = 1;
            } else {
                note = 0;
                break;
            }
        }
        vector<int> ans;
        if (note == 1) ans.push_back(1);
        for (int i = 0; i < n; ++i) {
            ans.push_back(digits[i]);
        }
        return ans;
    }
};
// @lc code=end
