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
        for (int i = 0; i < nums1.size(); i++) {
            bool find = false, done = false;
            for (int j = 0; j < nums2.size(); j++) {
                if (nums2[j] == nums1[i]) {
                    find = true;
                }
                if (find && !done) {
                    if (nums1[i] < nums2[j]) {
                        res[i] = nums2[j];
                        done = true;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    Solution sol;
    vector<int> res = sol.nextGreaterElement(nums1, nums2);
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}