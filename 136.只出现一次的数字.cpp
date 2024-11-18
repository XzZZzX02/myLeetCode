/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> umap{};
        for (auto& num : nums) {
            umap[num]++;
        }
        for (auto& [key, value] : umap) {
            if (value == 1) {
                return key;
            }
        }
        return -1;
    }
};
// @lc code=end
