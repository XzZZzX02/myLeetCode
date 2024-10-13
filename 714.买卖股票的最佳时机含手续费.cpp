/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int res = 0, n = prices.size();
        int minPrice = prices[0];
        for (int i = 0; i < n; i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
            if (prices[i] >= minPrice && prices[i] <= minPrice + fee) {
                continue;
            }
            if (prices[i] > minPrice + fee) {
                res += prices[i] - minPrice - fee;
                minPrice = prices[i] - fee;
            }
        }
        return res;
    }
};
// @lc code=end

