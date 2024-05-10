/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */
// @lc code=start
class Solution {
public:
    long mySqrt(int x) {
        if (x == 0) return 0;
        if (x == 1) return 1;
        long left = 1, right = x - 1;
        long ans = 0;
        long res = 0;
        while (left <= right) {
            long mid = left + (right - left) / 2;
            res = mid * mid;
            if (res == x)
                return mid;
            else if (res < x) {
                left = mid + 1;
                ans = mid;
            } else {
                right = mid - 1;
                ans = mid - 1;
            }
        }
        return ans;
    }
};
// @lc code=end
