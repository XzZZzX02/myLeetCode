/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int l = 0, r = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < nums.size(); i++) {
            r -= nums[i];
            if (l == r) {
                return i;
            } else {
                l += nums[i];
            }
        }
        return -1;
    }
};
// @lc code=end

