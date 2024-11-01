/*
 * @lc app=leetcode.cn id=3259 lang=cpp
 *
 * [3259] 超级饮料的最大强化能量
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA,
                             vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        long long a = energyDrinkA[0], b = energyDrinkB[0];
        for (int i = 1; i < n; i++) {
            long long c = max(a + energyDrinkA[i], b);
            b = max(b + energyDrinkB[i], a);
            a = c;
        }
        return a > b ? a : b;
    }
};
// @lc code=end
