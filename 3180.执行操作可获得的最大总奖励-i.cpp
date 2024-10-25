/*
 * @lc app=leetcode.cn id=3180 lang=cpp
 *
 * [3180] 执行操作可获得的最大总奖励 I
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        rewardValues.erase(unique(rewardValues.begin(), rewardValues.end()), rewardValues.end());
        int n = rewardValues.size();
        int m = rewardValues.back() * 2;
        int res = m - 1;
        vector<bool> dp(m, false);
        dp[0] = true;
        for (int i : rewardValues) {
            for (int j = 1; j < m; j++) {
                if (0 <= j - i && j - i < i) {
                    dp[j] = dp[j] || dp[j - i];
                }
            }
        }
        while (!dp[res]) {
            --res;
        }
        return res;
    }
};
// @lc code=end

