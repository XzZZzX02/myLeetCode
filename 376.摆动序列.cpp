/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int cur = 0, pre = 0, res = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            cur = nums[i + 1] - nums[i];
            if ((pre <= 0 && cur > 0) || (pre >= 0 && cur < 0)) {
                res++;
                pre = cur;
            }
        }
        return res;

        return res;
    }
};
// @lc code=end
#ifndef __ONLINE_JUDGE__
int main() {
    Solution s;
    vector<int> nums = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    int res = s.wiggleMaxLength(nums);
    cout << res << endl;
    return 0;
}
#endif