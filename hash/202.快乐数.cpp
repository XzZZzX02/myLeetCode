/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        int sum = 0;
        unordered_map<int, int> m;
        while (n != 1) {
            while (n) {
                int d = n % 10;
                n /= 10;
                sum += d * d;
            }
            n = sum;
            sum = 0;
            if (m[n]++ > 1) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
#ifndef __ONLINE_JUDGE__
int main() {
    Solution s;
    int n = 2;
    bool res = s.isHappy(n);
    cout << res << endl;
    return 0;
}
#endif