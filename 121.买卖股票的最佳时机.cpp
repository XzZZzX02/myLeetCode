/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include <climits>

#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, low = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            low = min(low, prices[i]);
            res = max(res, prices[i] - low);
        }
        return res;
    }
};
// @lc code=end
