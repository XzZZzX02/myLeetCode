/*
 * @lc app=leetcode.cn id=3244 lang=cpp
 *
 * [3244] 新增道路查询后的最短距离 II
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        vector<int> res;
        vector<int> next(n - 1);
        iota(next.begin(), next.end(), 1);
        int count = n - 1;
        for (auto& query : queries) {
            int x = query[0], y = query[1];
            if (next[x] && next[x] < y) {
                int i = next[x];
                while (i < y) {
                    --count;
                    int t = next[i];
                    next[i] = 0;
                    i = t;
                }
                next[x] = y;
            }
            res.push_back(count);
        }
        return res;
    }
};
// @lc code=end
