/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);
        for (int i = 1; i < candies.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        for (int j = ratings.size() - 2; j >= 0; j--) {
            if (ratings[j] > ratings[j + 1]) {
                candies[j] = max(candies[j], candies[j + 1] + 1);
            }
        }
        int res = 0;
        for (auto i : candies) {
            res += i;
        }
        return res;
    }
};
// @lc code=end
