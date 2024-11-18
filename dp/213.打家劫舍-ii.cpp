/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int rob_(vector<int>& nums, int start, int end) {
        if (end == start) {
            return nums[start];
        }
        vector<int> dp(end - start + 1, 0);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);
        for (int i = 2; i <= end - start; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[start + i]);
        }
        return dp[end - start];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }
        int res1 = rob_(nums, 0, n - 2);
        int res2 = rob_(nums, 1, n - 1);
        return max(res1, res2);
    }
};
// @lc code=end
