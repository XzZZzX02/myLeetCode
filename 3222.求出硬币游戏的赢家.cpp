/*
 * @lc app=leetcode.cn id=3222 lang=cpp
 *
 * [3222] 求出硬币游戏的赢家
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    string losingPlayer(int x, int y) {
        int k = min(x / 2, y / 8);
        x -= 2 * k;
        y -= 8 * k;
        return x && y >= 4 ? "Alice" : "Bob";
    }
};
// @lc code=end

