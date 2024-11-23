/*
 * @lc app=leetcode.cn id=3233 lang=cpp
 *
 * [3233] 统计不是特殊数字的数字数量
 */
#include "leetcode.h"
// @lc code=start
const int m = 31622;
int primes[m + 1];
auto init = [] {
    for (int i = 2; i <= m; i++) {
        if (primes[i] == 0) {
            primes[i] = primes[i - 1] + 1;
            for (int j = i * i; j <= m; j += i) {
                primes[j] = -1;
            }
        } else {
            primes[i] = primes[i - 1];
        }
    }
    return 0;
}();

class Solution {
public:
    int nonSpecialCount(int l, int r) {
        return r - l + 1 - (primes[(int)sqrt(r)] - primes[(int)sqrt(l - 1)]);
    }
};
// @lc code=end
