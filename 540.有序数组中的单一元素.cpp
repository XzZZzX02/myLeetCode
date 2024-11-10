/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] == nums[mid ^ 1]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return nums[l];
    }
};
// @lc code=end

