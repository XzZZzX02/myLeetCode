/*
 * @lc app=leetcode.cn id=3165 lang=cpp
 *
 * [3165] 不包含相邻元素的子序列的最大和
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        SegmentTree tree(n);
        for (int i = 0; i < n; ++i) {
            tree.modify(1, i + 1, nums[i]);
        }
        long long ans = 0;
        const int mod = 1e9 + 7;
        for (const auto& q : queries) {
            tree.modify(1, q[0] + 1, q[1]);
            ans = (ans + tree.query(1, 1, n)) % mod;
        }
        return (int) ans;
    }
};
// @lc code=end

