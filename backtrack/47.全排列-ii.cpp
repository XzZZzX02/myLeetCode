/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */
#include "leetcode.h"
// @lc code=start
class Solution {
    vector<vector<int>> res;
    vector<int> sub;

public:
    void backtracking(vector<int>& nums, vector<bool>& used) {
        if (sub.size() == nums.size()) {
            res.push_back(sub);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }
            if (!used[i]) {
                used[i] = true;
                sub.push_back(nums[i]);
                backtracking(nums, used);
                sub.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        res.clear();
        sub.clear();
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return res;
    }
};
// @lc code=end
