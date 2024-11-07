/*
 * @lc app=leetcode.cn id=3235 lang=cpp
 *
 * [3235] 判断矩形的两个角落是否可达
 */
#include "leetcode.h"
// @lc code=start
class Solution {
    bool in_circle(long long ox, long long oy, long long r, long long x,
                   long long y) {
        return (ox - x) * (ox - x) + (oy - y) * (oy - y) <= r * r;
    }

public:
    bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
        int n = circles.size();
        vector<int> vis(n);
        auto dfs = [&](auto&& dfs, int i) -> bool {
            long long x1 = circles[i][0], y1 = circles[i][1],
                      r1 = circles[i][2];
            if (y1 <= Y && abs(x1 - X) <= r1 || x1 <= X && y1 <= r1 ||
                x1 > X && in_circle(x1, y1, r1, X, 0)) {
                return true;
            }
            vis[i] = true;
            for (int j = 0; j < n; j++) {
                long long x2 = circles[j][0], y2 = circles[j][1],
                          r2 = circles[j][2];
                if (!vis[j] &&
                    (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <=
                        (r1 + r2) * (r1 + r2) &&
                    x1 * r2 + x2 * r1 < (r1 + r2) * X &&
                    y1 * r2 + y2 * r1 < (r1 + r2) * Y && dfs(dfs, j)) {
                    return true;
                }
            }
            return false;
        };
        for (int i = 0; i < n; i++) {
            long long x = circles[i][0], y = circles[i][1], r = circles[i][2];
            if (in_circle(x, y, r, 0, 0) || in_circle(x, y, r, X, Y) ||
                !vis[i] &&
                    (x <= X && abs(y - Y) <= r || y <= Y && x <= r ||
                     y > Y && in_circle(x, y, r, 0, Y)) &&
                    dfs(dfs, i)) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

