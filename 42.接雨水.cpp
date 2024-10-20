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
        stack<int> s;
        s.push(0);
        for (int i = 1; i < height.size(); i++) {
            while (!s.empty() && height[i] > height[s.top()]) {
                int index = s.top();
                s.pop();
                if (!s.empty()) {
                    int h = min(height[s.top()], height[i]) - height[index];
                    int w = i - s.top() - 1;
                    res += h * w;
                }
            }
            s.push(i);
        }
        return res;
    }
};
// @lc code=end

