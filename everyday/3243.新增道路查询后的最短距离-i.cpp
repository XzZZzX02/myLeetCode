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
        vector<int> res(queries.size());
        vector<vector<int>> from(n);
        vector<int> f(n);
        iota(f.begin(), f.end(), 0);
        for (int qi = 0; qi < queries.size(); qi++) {
            int l = queries[qi][0], r = queries[qi][1];
            from[r].push_back(l);
            if (f[l] + 1 < f[r]) {
                f[r] = f[l] + 1;
                for (int i = r + 1; i < n; i++) {
                    f[i] = min(f[i], f[i - 1] + 1);
                    for (int j : from[i]) {
                        f[i] = min(f[i], f[j] + 1);
                    }
                }
            }
            res[qi] = f[n - 1];
        }
        return res;
    }
};
// @lc code=end
