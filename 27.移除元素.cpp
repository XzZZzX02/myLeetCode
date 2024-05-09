/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != val) {
                nums[slow++] = nums[fast];
            }
        }
        return slow;
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