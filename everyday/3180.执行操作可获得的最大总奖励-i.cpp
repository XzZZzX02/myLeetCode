/*
 * @lc app=leetcode.cn id=3180 lang=cpp
 *
 * [3180] 执行操作可获得的最大总奖励 I
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        if (rewardValues.empty()) {
            return 0;
        }
        sort(rewardValues.begin(), rewardValues.end());
        rewardValues.erase(unique(rewardValues.begin(), rewardValues.end()), rewardValues.end());
        bitset<100000> dp{1};
        for (int v : rewardValues) {
            int shift = dp.size() - v;
            dp |= dp << shift >> (shift - v);
        }
        for (int i = rewardValues.back() * 2 - 1;; i--) {
            if (dp.test(i)) {
                return i;
            }
        }
    }
};
// @lc code=end

