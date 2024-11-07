/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int res;
        int sum = 0, add =0;
        for (auto v : nums) {
            sum += v;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (add * 2 == sum - nums[i]) {
                return i;
            }
            add += nums[i];    
        }
        return -1;
    }
};
// @lc code=end

