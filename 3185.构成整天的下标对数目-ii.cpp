/*
 * @lc app=leetcode.cn id=3185 lang=cpp
 *
 * [3185] 构成整天的下标对数目 II
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        if (hours.empty()) {
            return 0;
        }
        long long hash[24]{}, res = 0;
        for (auto hour : hours) {
            res += hash[(24 - hour % 24) % 24];
            hash[hour % 24]++;
        }
        return res;
    }
};
// @lc code=end

