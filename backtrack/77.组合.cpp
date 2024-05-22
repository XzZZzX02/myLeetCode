/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    void backtracking(vector<int>& num, vector<vector<int>>& re, int k,
                      int start, int max) {
        int n = num.size();
        int u = 0;
        if (n == k) {
            re.push_back(num);
            return;
        }
        for (int i = start; i <= max - k + n + 1; i++) {
            num.push_back(i);
            backtracking(num, re, k, i + 1, max);
            num.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        vector<vector<int>> res;
        backtracking(nums, res, k, 1, n);
        return res;
    }
};
// @lc code=end
