/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
<<<<<<< HEAD
    void backtracing(vector<vector<int>>& res, vector<int>& nums,
                     vector<int> const& candidates, vector<bool>& used,
                     int target, int start, int n) {
=======
    void backtracking(vector<vector<int>>& res, vector<int>& nums,
                      vector<int> const& candidates, vector<bool>& used,
                      int target, int start, int n) {
>>>>>>> 57a0b76 (40 1st 0ms backtracking+pruning)
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
<<<<<<< HEAD
            backtracing(res, nums, candidates, used, target - candidates[i],
                        i + 1, n);
=======
            backtracking(res, nums, candidates, used, target - candidates[i],
                         i + 1, n);
>>>>>>> 57a0b76 (40 1st 0ms backtracking+pruning)
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
<<<<<<< HEAD
        backtracing(res, nums, candidates, used, target, 0, n);
=======
        backtracking(res, nums, candidates, used, target, 0, n);
>>>>>>> 57a0b76 (40 1st 0ms backtracking+pruning)
        return res;
    }
};
// @lc code=end
