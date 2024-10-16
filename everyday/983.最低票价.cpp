/*
 * @lc app=leetcode.cn id=983 lang=cpp
 *
 * [983] 最低票价
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> day_set(days.begin(), days.end());
        int last_day = days.back();
        vector<int> dp(last_day + 1, 0);
        for (int i = 1; i < last_day + 1; i++) {
            if (day_set.find(i) == day_set.end()) {
                dp[i] = dp[i - 1];
            } else {
                dp[i] = min(dp[i - 1] + costs[0], min(dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]));
            }
        }
        return dp[last_day];
    }
};
// @lc code=end

