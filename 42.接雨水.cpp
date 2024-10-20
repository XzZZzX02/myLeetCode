/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        int res = 0;
        vector<int> maxLeft(height.size(), 0);
        vector<int> maxRight(height.size(), 0);
        int n = height.size();
        maxLeft[0] = height[0];
        maxRight[n - 1] = height[n - 1];
        for (int i = 1; i < n; i++) {
            maxLeft[i] = max(height[i], maxLeft[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            maxRight[i] = max(height[i], maxRight[i + 1]);
        }
        for (int i = 1; i < n - 1; i++) {
            int count = min(maxLeft[i], maxRight[i]) - height[i];
            if (count > 0) {
                res += count;
            }
        }
        return res;
    }
};
// @lc code=end

