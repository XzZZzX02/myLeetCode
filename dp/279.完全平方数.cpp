/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        auto isSquare = [](int x) {
            int s = (int)sqrt(x);
            return s * s == x;
        };
        auto check = [](int x) {
            while (!(x % 4)) {
                x /= 4;
            }
            return x % 8 == 7;
        };
        if (isSquare(n)) {
            return 1;
        }
        for (int i = 1; i * i <= n; i++) {
            if (isSquare(n - i * i)) {
                return 2;
            }
        }
        if (check(n)) {
            return 4;
        }
        return 3;
    }
};
// @lc code=end
#ifndef __ONLINE_JUDGE__
int main() {
    Solution s;
    int n = 12;
    int res = s.numSquares(n);
    cout << res << endl;
    return 0;
}
#endif