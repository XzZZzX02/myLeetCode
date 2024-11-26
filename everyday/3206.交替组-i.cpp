/*
 * @lc app=leetcode.cn id=3206 lang=cpp
 *
 * [3206] 交替组 I
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int res = 0, count = 0;
        int n = colors.size(), k = 3;
        for (int i = 0; i < n * 2; i++) {
            if (i > 0 && colors[i % n] == colors[(i - 1) % n]) {
                count = 0;
            }
            count++;
            res += i >= n && count >= k;
        }
        return res;
    }
};
// @lc code=end
