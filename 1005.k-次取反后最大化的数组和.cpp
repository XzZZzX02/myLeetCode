/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */
#include "leetcode.h"
// @lc code=start
class Solution {
    static bool cmp(int a, int b) { return abs(a) > abs(b); }

public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (k > 0 && nums[i] < 0) {
                nums[i] *= -1;
                k--;
            }
            sum += nums[i];
        }
        if (k % 2 != 0) {
            sum -= nums[nums.size() - 1] * 2;
        }
        return sum;
    }
};
// @lc code=end
#ifndef __ONLINE_JUDGE__
int main() {
    Solution s;
    vector<int> nums = {3, -3, 5, 6, 9};
    int res = s.largestSumAfterKNegations(nums, 2);
    cout << res << endl;
    return 0;
}
#endif