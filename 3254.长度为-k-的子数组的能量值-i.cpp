/*
 * @lc app=leetcode.cn id=3254 lang=cpp
 *
 * [3254] 长度为 K 的子数组的能量值 I
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n - k + 1, -1);
        int index = 0, l = 0, r = 0;
        for (int i = l; i < n; i++) {
            r = i;
            if (r - l + 1 == k) {
                res[index++] = test(nums, l, r);
                l++;
            }
        }
        return res;
    }

    int test(vector<int>& v, int start, int end) {
        for (int i = start; i < end; i++) {
            if (v[i + 1] - v[i] != 1) {
                return -1;
            }
        }
        return v[end];
    }
};
// @lc code=end

