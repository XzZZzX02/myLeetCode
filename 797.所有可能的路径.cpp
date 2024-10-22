/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> res;
        vector<int> path;
        path.push_back(0);
        dfs(graph, res, path, n, 0);
        return res;
    }

    void dfs(const vector<vector<int>>& graph, vector<vector<int>>& res, vector<int>& path, int n, int x) {
        if (x == n - 1) {
            res.push_back(path);
            return;
        }
        for (int i : graph[x]) {
            path.push_back(i);
            dfs(graph, res, path, n, i);
            path.pop_back();
        }
    }
};
// @lc code=end

