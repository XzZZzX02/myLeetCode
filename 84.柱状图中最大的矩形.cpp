/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        for (int i = 0; i < heights.size(); i++) {
            int l = i, r = i;
            for (;l >= 0; l--) {
                if (heights[l] < heights[i]) {
                    break;
                }
            }
            for (; r < heights.size(); r++) {
                if (heights[r] < heights[i]) {
                    break;
                }
            }
            res = max(res, (r - l - 1) * heights[i]);
        }
        return res;
    }
};
// @lc code=end

