/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty()) {
            return;
        }
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != 0) {
                nums[slow++] = nums[fast];
            }
        }
        for (int i = slow; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
// @lc code=end
