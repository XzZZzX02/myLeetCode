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
        int n = heights.size();
        vector<int> minLeft(heights.size()), minRight(heights.size());
        minLeft[0] = -1;
        for (int i = 1; i < n; i++) {
            int t = i - 1;
            while (t >= 0 && heights[t] >= heights[i]) {
                t = minLeft[t];
            }
            minLeft[i] = t;
        }
        minRight[n - 1] = n;
        for (int i = n - 2; i >= 0; i--) {
            int t = i + 1;
            while (t < n && heights[t] >= heights[i]) {
                t = minRight[t];
            }
            minRight[i] = t;
        }
        for (int i = 0; i < n; i++) {
            res = max(res, heights[i] * (minRight[i] - minLeft[i] - 1));
        }
        return res;
    }
};
// @lc code=end

