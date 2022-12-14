/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
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
    /// @brief kho qua huhuhuhuhu 😭
    /// @param prices value each day of stock
    /// @return value of best profit
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minPrice = 10000;
        int maxProfit = 0;
        for (int i = 0; i < n; ++i) {
            if (minPrice > prices[i]) {
                minPrice = prices[i];
            } else if (prices[i] - minPrice > maxProfit) {
                maxProfit = prices[i] - minPrice;
            }
        }

        return maxProfit;
    }
};
// @lc code=end
