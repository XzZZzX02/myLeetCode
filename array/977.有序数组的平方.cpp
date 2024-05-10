/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */
#include <cstdio>
#include <vector>

#include "leetcode.h"
// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        int res_i = n - 1;
        vector<int> res(n);
        while (i <= j) {
            if (nums[i] * nums[i] < nums[j] * nums[j]) {
                res[res_i--] = nums[j] * nums[j];
                j--;
            } else {
                res[res_i--] = nums[i] * nums[i];
                i++;
            }
        }
        return res;
    }
};
// @lc code=end
#ifndef __ONLINE_JUDGE__
int main() {
    Solution s;
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> res = s.sortedSquares(nums);
    for (int n : res) {
        cout << n << " ";
    }
    return 0;
}
#endif