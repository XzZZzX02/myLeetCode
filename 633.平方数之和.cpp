/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
        long long a = 0, b = sqrt(c);
        while (a <= b) {
            long long r = a * a + b * b;
            if (r == c) {
                return true;
            } else if (r > c) {
                b--;
            } else {
                a++;
            }
        }
        return false;
    }
};
// @lc code=end

