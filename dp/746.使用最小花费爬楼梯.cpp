/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() <= 1) {
            return 0;
        }
        int dp_0 = 0, dp_1 = 0, dp_i = 0;
        for (int i = 2; i <= cost.size(); i++) {
            dp_i = min(dp_1 + cost[i - 1], dp_0 + cost[i - 2]);
            dp_0 = dp_1;
            dp_1 = dp_i;
        }
        return dp_i;
    }
};
// @lc code=end
#ifndef __ONLINE_JUDGE__
int main() {
    Solution s;
    vector<int> cost = {10, 15, 20};
    int res = s.minCostClimbingStairs(cost);
    cout << res << endl;
    return 0;
}
#endif