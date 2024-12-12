/*
 * @lc app=leetcode.cn id=2931 lang=cpp
 *
 * [2931] 购买物品的最大开销
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        long long res = 0;
        int m = values.size(), n = values[0].size();
        vector<int> a;
        a.reserve(m * n);
        for (auto& row : values) {
            a.insert(a.end(), row.begin(), row.end());
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < a.size(); i++) {
            res += (long long)a[i] * (i + 1);
        }
        return res;
    }
};
// @lc code=end
