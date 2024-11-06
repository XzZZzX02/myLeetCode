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
        vector<int> indeg(n);
        vector<vector<int>> rg(n);
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            for (int j : graph[i]) {
                rg[j].push_back(i);
            }
            indeg[i] = graph[i].size();
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (int j : rg[i]) {
                if (--indeg[j] == 0) {
                    q.push(j);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                res.push_back(i);
            }
        }
        return res;
    }
};
// @lc code=end
