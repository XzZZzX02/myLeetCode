/*
 * @lc app=leetcode.cn id=3175 lang=cpp
 *
 * [3175] 找到连续赢 K 场比赛的第一位玩家
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int i = 0, count = 0, n = skills.size();
        k = min(k, n - 1);
        for (int j = 1; j < n; j++) {
            if (skills[i] < skills[j]) {
                count = 1;
                i = j;
            } else {
                count++;
            }
            if (count == k) {
                break;
            }
        }
        return  i;
    }
};
// @lc code=end

