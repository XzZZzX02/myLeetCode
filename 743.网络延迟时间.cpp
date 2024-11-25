/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> graph(n, vector<int>(n, INT_MAX / 2));
        for (auto& time : times) {
            graph[time[0] - 1][time[1] - 1] = time[2];
        }
        vector<int> distance(n, INT_MAX / 2), done(n);
        distance[k - 1] = 0;
        while (true) {
            int x = -1;
            for (int i = 0; i < n; i++) {
                if (!done[i] && (x == -1 || distance[i] < distance[x])) {
                    x = i;
                }
            }
            if (x < 0) {
                return *max_element(distance.begin(), distance.end());
            }
            if (distance[x] == INT_MAX / 2) {
                return -1;
            }
            done[x] = 1;
            for (int i = 0; i < n; i++) {
                distance[i] = min(distance[i], distance[x] + graph[x][i]);
            }
        }
    }
};
// @lc code=end
