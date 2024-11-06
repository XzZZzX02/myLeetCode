/*
 * @lc app=leetcode.cn id=3255 lang=cpp
 *
 * [3255] 长度为 K 的子数组的能量值 II
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (k == 1) {
            return nums;
        }
        int n = nums.size();
        if (n == 1) {
            return nums;
        }
        vector<int> res(n - k + 1);
        int dp[n];
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] == 1) {
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = 1;
            }
        }
        for (int i = k - 1; i < n; i++) {
            if (dp[i] >= k) {
                res[i - k + 1] = nums[i];
            } else {
                res[i - k + 1] = -1;
            }
        }
        return res;
    }
};
// @lc code=end

