/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */
#include "leetcode.h"
// @lc code=start
class Solution {
    vector<vector<int>> res;
    vector<int> subs;

public:
    void backtracking(vector<int>& nums, vector<bool>& used, int start) {
        res.push_back(subs);
        for (int i = start; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }
            subs.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, used, i + 1);
            used[i] = false;
            subs.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        res.clear();
        subs.clear();
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, used, 0);
        return res;
    }
};
// @lc code=end
