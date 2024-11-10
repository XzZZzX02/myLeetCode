/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = 0, r = 0;
        int m_new = m;
        while (l < m_new && r < n) {
            if (nums1[l] <= nums2[r]) {
                l++;
            } else {
                nums1.insert(nums1.begin() + l, nums2[r++]);
                m_new++;
            }
        }
        while (r < n) {
            nums1.insert(nums1.begin() + l++, nums2[r++]);
        }
        nums1.resize(m + n);
    }
};
// @lc code=end

