/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int dfs(int m, int n, int i, int j) {
        if (i > m || j > n) {
            return 0;
        }
        if (i == m && j == n) {
            return 1;
        }
        return dfs(m, n, i + 1, j) + dfs(m, n, i, j + 1);
    }
    int uniquePaths(int m, int n) { return dfs(m, n, 1, 1); }
};
// @lc code=end
