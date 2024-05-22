/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    void backtracking(vector<int>& num, vector<vector<int>>& res, int start,
                      int k, int nu, int sum, int target) {
        int n = num.size();

        if (n == k) {
            if (sum == target) {
                res.push_back(num);
            }
            return;
        }

        for (int i = start; i <= nu - k + n + 1; i++) {
            num.push_back(i);
            backtracking(num, res, i + 1, k, nu, sum + i, target);
            num.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> num;
        backtracking(num, res, 1, k, 9, 0, n);
        return res;
    }
};
// @lc code=end
