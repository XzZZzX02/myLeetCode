/*
 * @lc app=leetcode.cn id=3233 lang=cpp
 *
 * [3233] 统计不是特殊数字的数字数量
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int res = r - l + 1;
        auto isSpecial = [&](int n) -> bool {
            vector<int> factors;
            for (int i = 1; i < n; i++) {
                if (n % i == 0) {
                    factors.push_back(i);
                }
            }
            return factors.size() == 2;
        };
        for (int i = l; i <= r; i++) {
            if (isSpecial(i)) {
                res--;
            }
        }
        return res;
    }
};
// @lc code=end
