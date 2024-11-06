/*
 * @lc app=leetcode.cn id=3254 lang=cpp
 *
 * [3254] 长度为 K 的子数组的能量值 I
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n - k + 1, -1);
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

