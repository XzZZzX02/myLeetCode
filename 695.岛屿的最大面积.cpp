/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */
#include "leetcode.h"
// @lc code=start
class Solution {
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        vector<vector<bool>> visit(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!visit[i][j] && grid[i][j] == 1) {
                    visit[i][j] = true;
                    int area = 1;
                    dfs(grid, visit, i, j, area);
                    res = max(res, area);
                }                
            }
        }
        return res;
    }

    void dfs(const vector<vector<int>>& graph, vector<vector<bool>>& visit, int x, int y, int& area) {
        for (int i = 0; i < 4; i++) {
            int xNext = x + dir[i][0];
            int yNext = y + dir[i][1];
            if (xNext < 0 || xNext >= graph.size() || yNext < 0 || yNext >= graph[0].size()) {
                continue;
            }
            if (!visit[xNext][yNext] && graph[xNext][yNext] == 1) {
                visit[xNext][yNext] = true;
                area++;
                dfs(graph, visit, xNext, yNext, area);
            }
        }
    }
};
// @lc code=end

