/*
 * @lc app=leetcode.cn id=3243 lang=cpp
 *
 * [3243] 新增道路查询后的最短距离 I
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        vector<int> res;
        vector<vector<int>> city(n, vector<int>());
        for (int i = 0; i < n - 1; i++) {
            city[i].push_back(i + 1);
        }
        auto bfs = [&](int i) {
            queue<int> que{{i}};
            vector<int> visited(n, 0);
            visited[i] = 1;
            for (int d = 0;; d++) {
                for (int k = que.size(); k > 0; k--) {
                    int j = que.front();
                    que.pop();
                    if (j == n - 1) {
                        return d;
                    }
                    for (auto& k : city[j]) {
                        if (!visited[k]) {
                            visited[k] = 1;
                            que.push(k);
                        }
                    }
                }
            }
        };
        for (auto& q : queries) {
            city[q[0]].push_back(q[1]);
            res.push_back(bfs(0));
        }
        return res;
    }
};
// @lc code=end
