/*
 * @lc app=leetcode.cn id=561 lang=cpp
 *
 * [561] 数组拆分
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int res = 0;
        int minNum = INT_MAX, maxNum = INT_MIN;
        int dp[20001] = {0};
        for (auto& num : nums) {
            dp[num + 10000]++;
            minNum = min(minNum, num + 10000);
            maxNum = max(maxNum, num + 10000);
        }
        int j = 2;
        for (int i = minNum; i <= maxNum; i++) {
            while (dp[i]) {
                if (!(j % 2)) {
                    res += i - 10000;
                }
                dp[i]--;
                j++;
            }
        }
        return res;
    }
};
// @lc code=end
