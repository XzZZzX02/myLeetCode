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
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n] == INT_MAX ? -1 : dp[n];
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