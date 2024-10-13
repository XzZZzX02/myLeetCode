/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */
#include "leetcode.h"
#define v vector
#define _rep(i,a,b) for (int i=(a);i<(b);++i)
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int n = prices.size(), dp0 = 0, dp1;
        dp1 = INT_MIN;
        for (int i = 1;i < n + 1;++i) {
            int dp2 = max(dp0, dp1 + prices[i - 1]);
            dp1 = max(dp1, dp0 - prices[i - 1] - fee);
            dp0 = dp2;
        }
        return dp0;
    }
};
// @lc code=end

