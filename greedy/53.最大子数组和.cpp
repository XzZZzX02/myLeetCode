/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre_sum = 0, min_pre_sum = 0, res = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            pre_sum += nums[i];
            res = max(res, pre_sum - min_pre_sum);
            min_pre_sum = min(min_pre_sum, pre_sum);
        }
        return res;
    }
};
// @lc code=end
