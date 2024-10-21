/*
 * @lc app=leetcode.cn id=910 lang=cpp
 *
 * [910] 最小差值 II
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), 
            res = nums[n - 1] - nums[0];
        for (int i = 1; i < n; i++) {
            int mi = min(nums[0] + k, nums[i] - k);
            int mx = max(nums[i - 1] + k, nums[n - 1] - k);
            res = min(res, mx - mi);
        }
        return res;
    }
};
// @lc code=end
