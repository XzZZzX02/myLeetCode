/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N 皇后 II
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<int> columns(n, 0), diagonals1(2 * n - 1, 0),
            diagonals2(2 * n - 1, 0);
        auto dfs = [&](auto&& dfs, int row) {
            if (row == n) {
                res++;
                return;
            }
            for (int c = 0; c < n; c++) {
                int rc = row - c + n - 1;
                if (!columns[c] && !diagonals1[row + c] && !diagonals2[rc]) {
                    columns[c] = diagonals1[row + c] = diagonals2[rc] = 1;
                    dfs(dfs, row + 1);
                    columns[c] = diagonals1[row + c] = diagonals2[rc] = 0;
                }
            }
        };
        dfs(dfs, 0);
        return res;
    }
};
// @lc code=end
