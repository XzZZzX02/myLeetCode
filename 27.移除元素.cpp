/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
#include "leetcode.h"
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == val) {
                for (int j = i; j < nums.size() - 1; j++) {
                    nums[j] = nums[j + 1];
                }
                count++;
                i--;
                n--;
            }
        }
        return nums.size() - count;
    }
};
// @lc code=end
#ifndef __ONLINE_JUDGE__
int main() {
    Solution s;
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    int res = s.removeElement(nums, val);
    for (int i = 0; i < res; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}
#endif