/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0, t = 0;
        for (int n : nums) {
            sum += n;
        }
        if (target > sum) {
            return 0;
        }
        if ((target + sum) % 2) {
            return false;
        }
        if (abs(target) > sum) {
            return false;
        }
        t = (target + sum) / 2;
        vector<int> dp(5001, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = t; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[t];
    }
};
// @lc code=end
