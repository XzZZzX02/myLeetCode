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
        heights.push_back(0);
        int n = heights.size();
        vector<int> vec;
        int res = 0;
        for (int i = 0; i < n; i++) {
            while (!vec.empty() && heights[vec.back()] > heights[i]) {
                int out = vec.back();
                vec.pop_back();
                res = max(res, heights[out] *
                                   (vec.empty() ? i : i - (vec.back() + 1)));
            }
            vec.push_back(i);
        }
        return res;
    }
};
// @lc code=end

