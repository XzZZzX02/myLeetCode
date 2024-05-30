/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(101, vector(101, 0));
        for (const auto& str : strs) {
            int _1_num = 0, _0_num = 0;
            for (const auto& c : str) {
                if (c - '0') {
                    _0_num++;
                } else {
                    _1_num++;
                }
            }
            for (int i = m; i >= _1_num; i--) {
                for (int j = n; j >= _0_num; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - _1_num][j - _0_num] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end
