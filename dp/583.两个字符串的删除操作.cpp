/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        string text1 = word1, text2 = word2;
        int m = text1.size(), n = text2.size();
        vector<int> dp(n + 1, 0);
        for (int j = 0; j <= n; ++j)
            dp[j] = j;
        int left_up, tmp_left_up;
        for (int i = 1; i <= m; i++) {
            tmp_left_up = dp[0];
            dp[0] = i;
            left_up = tmp_left_up;
            for (int j = 1; j <= n; j++) {
                int result = min(dp[j-1]+1, dp[j]+1);
                if (text1[i - 1] == text2[j - 1])
                    result = min(result, left_up);
                tmp_left_up = dp[j];
                dp[j] = result;
                left_up = tmp_left_up;
            }
        }
        return dp[n];
    }
};
// @lc code=end

