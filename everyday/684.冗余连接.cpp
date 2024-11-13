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
        UnionFind uf(edges.size());
        for (int i = 0;; i++) {
            if (!uf.unite(edges[i][0] - 1, edges[i][1] - 1)) {
                return edges[i];
            }
        }
    }
};
// @lc code=end

