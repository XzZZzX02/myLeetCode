/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include <vector>

#include "leetcode.h"
// @lc code=start
class Solution {
    vector<vector<int>> res;
    vector<int> subs;

public:
    void backtracking(vector<int>& nums, int start) {
        res.push_back(subs);
        for (int i = start; i < nums.size(); i++) {
            subs.push_back(nums[i]);
            backtracking(nums, i + 1);
            subs.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        subs.clear();
        backtracking(nums, 0);
        return res;
    }
};
// @lc code=end
