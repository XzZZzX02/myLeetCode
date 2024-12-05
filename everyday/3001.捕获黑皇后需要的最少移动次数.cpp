/*
 * @lc app=leetcode.cn id=3001 lang=cpp
 *
 * [3001] 捕获黑皇后需要的最少移动次数
 */
#include "leetcode.h"
// @lc code=start
class Solution {
    bool inBetween(int a, int b, int c) {
        return min(a, c) <= b && b <= max(a, c);
    }

public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if (a == e && (c != e || !inBetween(b, d, f)) ||
            b == f && (d != f || !inBetween(a, c, e)) ||
            c + d == e + f && (a + b != e + f || !inBetween(c, a, e)) ||
            c - d == e - f && (a - b != e - f || !inBetween(c, a, e))) {
            return 1;
        }
        return 2;
    }
};
// @lc code=end
