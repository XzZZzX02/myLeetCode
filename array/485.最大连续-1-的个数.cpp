/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续 1 的个数
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, cnt = 0;
        for (auto v : nums) {
            if (!v) {
                cnt = 0;
            } else {
                cnt++;
                res = max(res, cnt);
            }
        }
        return res;
    }
};
// @lc code=end

