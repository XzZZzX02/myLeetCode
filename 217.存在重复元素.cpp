/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        return set.size() != nums.size();
    }
};
// @lc code=end
