/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        for (int i = 0; i < n; i++) {
            int pa = find(edges[i][0] - 1, p);
            int pb = find(edges[i][1] - 1, p);
            if (pa == pb) {
                return edges[i];
            }
            p[pa] = pb;
        }
        return edges[n - 1];
    }

    int find(int x, vector<int>& p) {
        return x == p[x] ? x : p[x] = find(p[x], p);
    }
};
// @lc code=end

