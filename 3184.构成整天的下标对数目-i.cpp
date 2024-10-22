/*
 * @lc app=leetcode.cn id=3184 lang=cpp
 *
 * [3184] 构成整天的下标对数目 I
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int hash[24]{}, res = 0;
        for (auto hour : hours) {
            res += hash[(24 - hour % 24) % 24];
            hash[hour % 24]++;
        }
        return res;
    }
};
// @lc code=end

