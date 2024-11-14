/*
 * @lc app=leetcode.cn id=3239 lang=cpp
 *
 * [3239] 最少翻转次数使二进制矩阵回文 I
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int diffRow = 0, diffCol = 0;
        for (auto& row : grid) {
            for (int j = 0; j < n / 2; j++) {
                diffRow += row[j] != row[n - 1 - j];
            }
        }
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m / 2; i++) {
                diffCol += grid[i][j] != grid[m - 1 - i][j];
            }
        }
        return min(diffRow, diffCol);
    }
};
// @lc code=end

