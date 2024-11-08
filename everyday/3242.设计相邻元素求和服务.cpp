/*
 * @lc app=leetcode.cn id=3242 lang=cpp
 *
 * [3242] 设计相邻元素求和服务
 */
#include "leetcode.h"
// @lc code=start
class NeighborSum {
    vector<vector<int>> __grid;
    int m, n;
public:
    NeighborSum(vector<vector<int>>& grid) {
        __grid = grid;
        m = grid.size();
        n = grid[0].size();
    }
    
    int adjacentSum(int value) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (__grid[i][j] == value) {
                    int sum = 0;
                    if (i > 0) {
                        sum += __grid[i - 1][j];
                    }
                    if (i < m - 1) {
                        sum += __grid[i + 1][j];
                    }
                    if (j > 0) {
                        sum += __grid[i][j - 1];
                    }
                    if (j < n - 1) {
                        sum += __grid[i][j + 1];
                    }
                    return sum;
                }
            }
        }
        return -1;
    }
    
    int diagonalSum(int value) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (__grid[i][j] == value) {
                    int sum = 0;
                    if (i > 0 && j > 0) {
                        sum += __grid[i - 1][j - 1];
                    }
                    if (i > 0 && j < n - 1) {
                        sum += __grid[i - 1][j + 1];
                    }
                    if (i < m - 1 && j > 0) {
                        sum += __grid[i + 1][j - 1];
                    }
                    if (i < m - 1 && j < n - 1) {
                        sum += __grid[i + 1][j + 1];
                    }
                    return sum;
                }
            }
        }
        return -1;
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
// @lc code=end

