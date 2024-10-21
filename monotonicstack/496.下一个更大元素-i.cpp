/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty()) {
            return {};
        }
        vector<int> res(nums1.size(), -1);
        stack<int> s;
        unordered_map<int, int> umap;
        for (int i = 0; i < nums1.size(); i++) {
            umap[nums1[i]] = i;
        }
        s.push(0);
        for (int i = 1; i < nums2.size(); i++) {
            while (!s.empty() && nums2[i] > nums2[s.top()]) {
                if (umap.count(nums2[s.top()]) > 0) {
                    int index = umap[nums2[s.top()]];
                    res[index] = nums2[i];
                }
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};
// @lc code=end
