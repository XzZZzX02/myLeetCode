/*
 * @lc app=leetcode.cn id=908 lang=cpp
 *
 * [908] 最小差值 I
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        auto p = minmax_element(nums.begin(), nums.end());
        return max(0, *p.second - 2 * k - *p.first);
    }
};
// @lc code=end

