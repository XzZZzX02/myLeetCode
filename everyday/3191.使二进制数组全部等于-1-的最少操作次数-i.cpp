/*
 * @lc app=leetcode.cn id=3191 lang=cpp
 *
 * [3191] 使二进制数组全部等于 1 的最少操作次数 I
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        int n = nums.size(); 
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (i + 2 >= n) {
                    return -1;
                } else {
                    res++;
                    nums[i + 1] ^= 1;
                    nums[i + 2] ^= 1;
                }
            }
        }
        return res;
    }
};
// @lc code=end

