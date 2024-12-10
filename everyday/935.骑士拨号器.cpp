/*
 * @lc app=leetcode.cn id=935 lang=cpp
 *
 * [935] 骑士拨号器
 */
#include "leetcode.h"
// @lc code=start
const int MOD = 1'000'000'007;
const vector<int> NEXT[10] = {{4, 6}, {6, 8},    {7, 9}, {4, 8}, {0, 3, 9},
                              {},     {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
int memo[5000][10];

int dfs(int i, int j) {
    if (i == 0) {
        return 1;
    }
    int& res = memo[i][j];
    if (res) {
        return res;
    }
    for (int k : NEXT[j]) {
        res = (res + dfs(i - 1, k)) % MOD;
    }
    return res;
}

class Solution {
public:
    int knightDialer(int n) {
        if (n == 1) {
            return 10;
        }
        long long ans = 0;
        for (int j = 0; j < 10; j++) {
            ans += dfs(n - 1, j);
        }
        return ans % MOD;
    }
};
// @lc code=end
