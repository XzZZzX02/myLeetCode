/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        if (num == 4) return true;
        if (num == 9) return true;
        if (num == 16) return true;
        if (num == 25) return true;
        if (num == 36) return true;
        if (num == 49) return true;
        if (num == 64) return true;
        if (num == 81) return true;
        int left = 1;
        int right = num - 1;
        long mid = 0;
        long square = 0;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            square = mid * mid;
            if (square < num) {
                left = mid + 1;
            } else if (square == num) {
                return true;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};
// @lc code=end
#ifndef __ONLINE_JUDGE__
#include "leetcode.h"
int main() {
    Solution s;
    int num = 808201;
    bool res = s.isPerfectSquare(num);
    cout << res << endl;
    return 0;
}
#endif