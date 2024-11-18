/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    bool isValid(int row, int col, char num,
                 vector<vector<char>> const& board) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num || board[i][col] == num) {
                return false;
            }
            int start_row = row / 3 * 3;
            int start_col = col / 3 * 3;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i + start_row][j + start_col] == num) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool backtracking(vector<vector<char>>& board) {
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board.size(); col++) {
                if (board[row][col] != '.') {
                    continue;
                }
                for (char num = '1'; num <= '9'; num++) {
                    if (isValid(row, col, num, board)) {
                        board[row][col] = num;
                        if (backtracking(board)) {
                            return true;
                        }
                        board[row][col] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) { backtracking(board); }
};
// @lc code=end
