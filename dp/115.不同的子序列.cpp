/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<unsigned long long>> dp(n,vector<unsigned long long>(m,0));
        dp[0][0]=(s[0]==t[0])?1:0;
        for(int i = 1; i < n; ++i){
            dp[i][0] = dp[i-1][0];
            if(s[i]==t[0])dp[i][0]++;
        }
        for(int i = 1; i < n; ++i){
            for(int j = 1; j < m && j <= i; ++j){
                if(s[i]==t[j])dp[i][j] = dp[i-1][j]+dp[i-1][j-1];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n-1][m-1];
    }
};
// @lc code=end

