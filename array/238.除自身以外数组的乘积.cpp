/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int l = 1, r = 1;
        for (int i = 0; i < n; i++) {
            res[i] = l;
            l *= nums[i];
        }
        for (int i = n - 1; i >=0; i--) {
            res[i] *= r;
            r *= nums[i];
        }
        return res;
    }
};
// @lc code=end

