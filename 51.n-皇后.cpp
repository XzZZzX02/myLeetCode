/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> queens(n, -1);
        vector<int> columns(n, 0), diagonals1(2 * n - 1, 0),
            diagonals2(2 * n - 1, 0);
        auto dfs = [&](auto&& dfs, int row) {
            if (row == n) {
                vector<string> board(n);
                for (int i = 0; i < n; i++) {
                    board[i] = string(queens[i], '.') + 'Q' +
                               string(n - queens[i] - 1, '.');
                }
                res.push_back(board);
                return;
            }
            for (int c = 0; c < n; c++) {
                int rc = row - c + n - 1;
                if (!columns[c] && !diagonals1[row + c] && !diagonals2[rc]) {
                    queens[row] = c;
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
