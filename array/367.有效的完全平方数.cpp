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
        int odd = 1;
        while (num > 0) {
            num -= odd;
            odd += 2;
        }
        return num == 0;
    }
};
// @lc code=end
