/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int res = 0, cur = 0, next = 0;
        for (int i = 0; i < nums.size(); i++) {
            next = max(i + nums[i], next);
            if (i == cur) {
                res++;
                cur = next;
                if (next >= nums.size() - 1) break;
            }
        }
        return res;
    }
};
// @lc code=end
