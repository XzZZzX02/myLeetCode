/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int m = INT_MIN;
        for (auto v : nums) {
            m = max(m, v);
            ++count[v];
        }
        for (int i = m; ; --i) {
            k -= count[i];
            if (k <= 0) {
                return i;
            }
        }
        return 0;
    }
};
// @lc code=end

