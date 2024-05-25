/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        int res = 0;
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end
#ifndef __ONLINE_JUDGE__
int main() {
    Solution s;
    int m = 3, n = 7;
    int res = s.uniquePaths(3, 7);
    cout << res << endl;
    return 0;
}
#endif