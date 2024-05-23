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
        int res = INT_MIN, count = 0;
        for (int i : nums) {
            count += i;
            res = count > res ? count : res;
            if (count < 0) {
                count = 0;
                continue;
            }
        }
        return res;
    }
};
// @lc code=end
