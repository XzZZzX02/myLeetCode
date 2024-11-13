/*
 * @lc app=leetcode.cn id=3249 lang=cpp
 *
 * [3249] 统计好节点的数目
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int res = 0, n = edges.size() + 1;
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        auto dfs = [&](auto&& dfs, int i, int fa) -> int {
            int sum = 0, first = -1, flag = 1;
            for (int j : g[i])
                if (j != fa) {
                    int num = dfs(dfs, j, i);
                    sum += num;
                    if (first == -1) {
                        first = num;
                    } else if (num != first) {
                        flag = 0;
                    }
                }
            if (flag) {
                res++;
            }
            return sum + 1;
        };
        dfs(dfs, 0, -1);
        return res;
    }
};
// @lc code=end
