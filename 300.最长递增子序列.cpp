/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        vector<int> dp;
        for (int num : nums) {
            auto it = lower_bound(dp.begin(), dp.end(), num);
            if (it == dp.end()) {
                dp.push_back(num);
            } else {
                *it = num;
            }
        }
        return dp.size();
    }
};
// @lc code=end

