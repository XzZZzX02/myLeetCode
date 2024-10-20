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
        for (int i = 1; i < height.size() - 1; i++) {
            int lHeight = height[i], rHeight = height[i];
            for (int l = i - 1; l >= 0; l--) {
                if (height[l] > lHeight) {
                    lHeight = height[l];
                }
            }
            for (int r = i + 1; r < height.size(); r++) {
                if (height[r] > rHeight) {
                    rHeight = height[r];
                }
            }
            res += min(lHeight, rHeight) - height[i];
        }
        return res;
    }
};
// @lc code=end

