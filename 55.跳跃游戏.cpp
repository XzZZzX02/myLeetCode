/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0, n = nums.size();
        if (n <= 1) {
            return true;
        }
        for (int i = 0; i <= cover; i++) {
            cover = cover > i + nums[i] ? cover : i + nums[i];
            if (cover >= n - 1) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
#ifndef __ONLINE_JUDGE__
int main() {
    Solution s;
    vector<int> nums = {3, 2, 1, 0, 4};
    bool res = s.canJump(nums);
    cout << res << endl;
    return 0;
}
#endif