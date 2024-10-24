/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // dfs
        return dfs(nums, target, 0, 0);
    }

    int dfs(vector<int>& nums, int target, int index, int sum) {
        if (index == nums.size()) {
            return sum == target ? 1 : 0;
        }
        return dfs(nums, target, index + 1, sum + nums[index]) + dfs(nums, target, index + 1, sum - nums[index]);
    }
};
// @lc code=end

