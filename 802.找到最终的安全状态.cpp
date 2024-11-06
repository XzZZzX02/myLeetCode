/*
 * @lc app=leetcode.cn id=802 lang=cpp
 *
 * [802] 找到最终的安全状态
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        int n = graph.size();
        vector<int> color(n, 0);
        for (int i = 0; i < n; i++) {
            if (dfs(i, color, graph)) {
                res.push_back(i);
            }
        }
        return res;
    }

    bool dfs(int x, vector<int>& color, vector<vector<int>>& graph) {
        if (color[x]) {
            return color[x] == 2;
        }
        color[x] = 1;
        for (auto v : graph[x]) {
            if (!dfs(v, color, graph)) {
                return false;
            }
        }
        color[x] = 2;
        return true;
    }
};
// @lc code=end

