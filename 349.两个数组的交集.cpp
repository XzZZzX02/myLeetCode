/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */
#include <unordered_set>

#include "leetcode.h"
// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set(nums1.begin(), nums1.end());
        vector<int> res;
        for (int num : set) {
            if (nums2.end() != find(nums2.begin(), nums2.end(), num)) {
                res.push_back(num);
            }
        }
        return res;
    }
};
// @lc code=end
