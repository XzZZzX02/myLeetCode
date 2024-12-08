/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int i = 0, j = 0, k = nums.size() - 1; j <= k;) {
            if (nums[j] == 0) {
                swap(nums[i++], nums[j++]);
            } else if (nums[j] == 1) {
                j++;
            } else {
                swap(nums[j], nums[k--]);
            }
        }
    }
};
// @lc code=end

