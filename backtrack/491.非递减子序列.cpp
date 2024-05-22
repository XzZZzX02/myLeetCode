/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 非递减子序列
 */
#include "leetcode.h"
// @lc code=start
class Solution {
    vector<vector<int>> res;
    vector<int> subs;

public:
    void backtracking(vector<int>& nums, int start) {
        if (subs.size() > 1) {
            res.push_back(subs);
        }
        int used[201] = {0};
        for (int i = start; i < nums.size(); i++) {
            if ((!subs.empty() && nums[i] < subs.back()) ||
                used[nums[i] + 100] == 1) {
                continue;
            }
            used[nums[i] + 100] = 1;
            subs.push_back(nums[i]);
            backtracking(nums, i + 1);
            subs.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        res.clear();
        subs.clear();
        backtracking(nums, 0);
        return res;
    }
};
// @lc code=end
