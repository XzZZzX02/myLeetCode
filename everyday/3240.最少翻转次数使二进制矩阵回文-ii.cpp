/*
 * @lc app=leetcode.cn id=3240 lang=cpp
 *
 * [3240] 最少翻转次数使二进制矩阵回文 II
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                int oneCount = grid[i][j] + grid[i][n - 1 - j] + grid[m - 1 - i][j] + grid[m - 1 - i][n - 1 - j];
                res += min(oneCount, 4 - oneCount);
            }
        }
        if (m % 2 && n % 2) {
            res += grid[m / 2][n / 2];
        }
        int diff = 0, count = 0;
        if (m % 2) {
            for (int j = 0; j < n / 2; j++) {
                if (grid[m / 2][j] != grid[m / 2][n - 1 - j]) {
                    diff++;
                } else {
                    count += grid[m / 2][j] * 2;
                }
            }
        }
        if (n % 2) {
            for (int i = 0; i < m / 2; i++) {
                if (grid[i][n / 2] != grid[m - 1 - i][n / 2]) {
                    diff++;
                } else {
                    count += grid[i][n / 2] * 2;
                }
            }
        }
        return res + (diff ? diff : count % 4);
    }
};
// @lc code=end

