/*
 * @lc app=leetcode.cn id=632 lang=cpp
 *
 * [632] 最小区间
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
            heap;
        int right = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            heap.emplace(nums[i][0], i, 0);
            right = max(right, nums[i][0]);
        }
        int resLeft = get<0>(heap.top());
        int resRihgt = right;
        while (true) {
            auto [_, i, j] = heap.top();
            if (j + 1 == nums[i].size()) {
                break;
            }
            heap.pop();
            int x = nums[i][j + 1];
            heap.emplace(x, i, j + 1);
            right = max(right, x);
            int left = get<0>(heap.top());
            if (right - left < resRihgt - resLeft) {
                resLeft = left;
                resRihgt = right;
            }
        }
        return {resLeft, resRihgt};
    }
};
// @lc code=end
