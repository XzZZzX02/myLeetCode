/*
 * @lc app=leetcode.cn id=3238 lang=cpp
 *
 * [3238] 求出胜利玩家的数目
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        int res = 0;
        vector<vector<int>> umap(n, vector<int>(11, 0));
        for (auto& p : pick) {
            umap[p[0]][p[1]]++;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 11; j++) {
                if (umap[i][j] > i) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end
