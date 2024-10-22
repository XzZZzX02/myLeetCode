/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */
#include "leetcode.h"
// @lc code=start
class Solution {
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        vector<vector<bool>> visit(grid.size(), vector<bool>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!visit[i][j] && grid[i][j] == '1') {
                    res++;
                    visit[i][j] = true;
                    dfs(grid, visit, i, j);
                }
            }
        }
        return res;
    }

    void dfs(const vector<vector<char>>& graph, vector<vector<bool>>& visit, int x, int y) {
        for (int i = 0; i < 4; i++) {
            int xNext = x + dir[i][0];
            int yNext = y + dir[i][1];
            if (xNext < 0 || xNext >= graph.size() || yNext < 0 || yNext > graph[0].size()) {
                continue;
            }
            if (!visit[xNext][yNext] && graph[xNext][yNext] == '1') {
                visit[xNext][yNext] = true;
                dfs(graph, visit, xNext, yNext);
            }
        }
    }
};
// @lc code=end

