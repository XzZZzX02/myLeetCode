/*
 * @lc app=leetcode.cn id=825 lang=cpp
 *
 * [825] 适龄的朋友
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int res = 0;
        vector<int> nums(130, 0);
        for (auto& a : ages) {
            nums[a]++;
        }
        for (int i = 1; i < 130; i++) {
            nums[i] += nums[i - 1];
        }
        for (int y = 1, x = 1; y < 130; y++) {
            if (!(nums[y] - nums[y - 1])) {
                continue;
            }
            if (x < y) {
                x = y;
            }
            while (x < 130 && check(x, y)) {
                x++;
            }
            int temp = nums[x - 1] - nums[y - 1] - 1;
            if (temp > 0) {
                res += temp * (nums[y] - nums[y - 1]);
            }
        }
        return res;
    }
    bool check(int x, int y) {
        if (y <= 0.5 * x + 7) {
            return false;
        }
        if (y > x) {
            return false;
        }
        if (y > 100 && x < 100) {
            return false;
        }
        return true;
    }
};
// @lc code=end
