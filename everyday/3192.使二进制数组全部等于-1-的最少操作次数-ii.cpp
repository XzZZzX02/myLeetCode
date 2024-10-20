/*
 * @lc app=leetcode.cn id=3192 lang=cpp
 *
 * [3192] 使二进制数组全部等于 1 的最少操作次数 II
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0, v = 0;
        for (int n : nums) {
            n ^= v;
            if (n == 0) {
                v ^= 1;
                res++;
            }
        }
        return res;
    }
};
// @lc code=end

