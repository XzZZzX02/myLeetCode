/*
 * @lc app=leetcode.cn id=3274 lang=cpp
 *
 * [3274] 检查棋盘方格颜色是否相同
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        auto x1 = coordinate1[0] - 'A', y1 = coordinate1[1] - '1';
        auto x2 = coordinate2[0] - 'A', y2 = coordinate2[1] - '1';
        return (x1 + y1) % 2 == (x2 + y2) % 2;
    }
};
// @lc code=end
