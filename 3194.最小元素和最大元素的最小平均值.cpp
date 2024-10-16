/*
 * @lc app=leetcode.cn id=3194 lang=cpp
 *
 * [3194] 最小元素和最大元素的最小平均值
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = INT_MAX;
        for (int i = 0; i < n / 2; i++) {
            res = min(res, nums[i] + nums[n - i - 1]);
        }
        return res / 2.0;
    }
};
// @lc code=end

