/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */
#include <climits>

#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int j = 0;
        int sum = 0;
        int res = INT_MAX;
        while (j < nums.size()) {
            sum += nums[j];
            while (sum >= target) {
                res = res < j - i + 1 ? res : j - i + 1;
                sum -= nums[i++];
            }
            j++;
        }
        return res == INT_MAX ? 0 : res;
    }
};
// @lc code=end
