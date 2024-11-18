/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int k = 0;
        for (auto& num : nums) {
            k ^= num;
        }
        return k;
    }
};
// @lc code=end
