/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            int y = target - nums[i];
            if (m.count(y)) {
                return {m[y], i};
            }
            m[x] = i;
        }
        return {};
    }
};
// @lc code=end
