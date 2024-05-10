/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                     vector<int>& nums4) {
        unordered_map<int, int> m;
        int res = 0;
        for (int a : nums1) {
            for (int b : nums2) {
                m[a + b]++;
            }
        }
        for (int c : nums3) {
            for (int d : nums4) {
                if (m.count(0 - c - d) != 0) {
                    res += m[0 - c - d];
                }
            }
        }
        return res;
    }
};
// @lc code=end
