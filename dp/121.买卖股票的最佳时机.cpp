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
        vector<int> dp(prices.size(), 0);
        int min_ = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            min_ = min(min_, prices[i]);
            dp[i] = max(dp[i - 1], prices[i] - min_);
        }
        return dp[prices.size() - 1];
    }
};
// @lc code=end
#ifndef __ONLINE_JUDGE__
int main() {
    Solution s;
    vector<int> prices = {1, 2};
    int res = s.maxProfit(prices);
    cout << res << endl;
    return 0;
}
#endif