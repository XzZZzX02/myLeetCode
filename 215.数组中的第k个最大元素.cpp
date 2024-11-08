/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        return quickSelect(0, nums.size() - 1, k, nums);
    }

    int quickSelect(int l, int r, int k, vector<int>& nums) {
        if (l == r) {
            return nums[l];
        }
        int i = l - 1, j = r + 1, x = nums[(l + r) >> 1];
        while (i < j) {
            while (nums[++i] < x);
            while (nums[--j] > x);
            if (i < j) {
                swap(nums[i], nums[j]);
            }
        }
        if (j < k) {
            return quickSelect(j + 1, r, k, nums);
        } else {
            return quickSelect(l, j, k, nums);
        }
    }
};
// @lc code=end

