/*
 * @lc app=leetcode.cn id=3248 lang=cpp
 *
 * [3248] 矩阵中的蛇
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i = 0, j = 0;
        for (auto& command : commands) {
            if (command == "UP") {
                i--;
            } else if (command == "DOWN") {
                i++;
            } else if (command == "LEFT") {
                j--;
            } else if (command == "RIGHT") {
                j++;
            }
        }
        return i * n + j;
    }
};
// @lc code=end
