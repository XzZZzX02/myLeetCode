/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            res = max(res, nums[i] - nums[i - 1]);
        }
        return res;
    }
};
// @lc code=end

