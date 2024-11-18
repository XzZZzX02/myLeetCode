/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include "leetcode.h"
// @lc code=start
class Solution {
    vector<vector<int>> res;
    vector<int> arrange;

public:
    void backtracking(vector<int>& nums, vector<bool>& used) {
        if (arrange.size() == nums.size()) {
            res.push_back(arrange);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            used[i] = true;
            arrange.push_back(nums[i]);
            backtracking(nums, used);
            arrange.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        arrange.clear();
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return res;
    }
};
// @lc code=end
