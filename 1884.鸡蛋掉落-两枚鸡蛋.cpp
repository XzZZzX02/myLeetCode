/*
 * @lc app=leetcode.cn id=1884 lang=cpp
 *
 * [1884] 鸡蛋掉落-两枚鸡蛋
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int twoEggDrop(int n) {
        vector<vector<int>> dp(3, vector<int>(n + 1, 0));
        int m = 0;
        while (dp[2][m] < n) {
            m++;
            dp[1][m] = m;
            dp[2][m] = dp[1][m - 1] + dp[2][m - 1] + 1;
        }        
        return m;
    }
};
// @lc code=end

