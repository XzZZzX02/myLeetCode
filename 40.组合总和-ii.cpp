/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    void backtracing(vector<vector<int>>& res, vector<int>& nums,
                     vector<int> const& candidates, vector<bool>& used,
                     int target, int start, int n) {
        if (target <= 0) {
            if (!target) {
                res.push_back(nums);
            }
            return;
        }
        for (int i = start; i < n && target - candidates[i] >= 0; i++) {
            if (i > 0 && candidates[i] == candidates[i - 1] &&
                used[i - 1] == false) {
                continue;
            }
            nums.push_back(candidates[i]);
            used[i] = true;
            backtracing(res, nums, candidates, used, target - candidates[i],
                        i + 1, n);
            used[i] = false;
            nums.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> nums;
        int n = candidates.size();
        vector<bool> used(n, false);
        sort(candidates.begin(), candidates.end());
        backtracing(res, nums, candidates, used, target, 0, n);
        return res;
    }
};
// @lc code=end
