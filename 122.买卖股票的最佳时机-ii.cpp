/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prof = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] - prices[i - 1] > 0) {
                prof += prices[i] - prices[i - 1];
            }
        }
        return prof;
    }
};
// @lc code=end
