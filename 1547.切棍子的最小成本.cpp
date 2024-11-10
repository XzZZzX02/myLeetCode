/*
 * @lc app=leetcode.cn id=1547 lang=cpp
 *
 * [1547] 切棍子的最小成本
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int dp[105][105] = {0};
        sort(cuts.begin(), cuts.end());
        int cnt = cuts.size();
        vector<int> num(cnt + 2);
        num[0] = 0;
        num[cnt + 1] = n;
        for (int i = 1; i <= cnt; i++) num[i] = cuts[i - 1];
        for (int len = 3; len <= cnt + 2; len++) {
            for (int i = 0; i + len - 1 < cnt + 2; i++) {
                int j = i + len - 1;
                dp[i][j] = 1e9 + 7;
                for (int k = i + 1; k + 1 <= j; k++) {
                    dp[i][j] =
                        min(dp[i][j], dp[i][k] + dp[k][j] + num[j] - num[i]);
                }
            }
        }
        return dp[0][cnt + 1];
    }
};
// @lc code=end

