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
        unordered_set<int> res_set;
        for (int num : nums2) {
            if (set.count(num) > 0) {
                res_set.insert(num);
            }
        }
        return vector<int>(res_set.begin(), res_set.end());
    }
};
// @lc code=end
