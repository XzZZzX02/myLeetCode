/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if (bills[0] != 5) {
            return false;
        }
        int _5 = 0, _10 = 0, _20 = 0;
        for (int dol : bills) {
            if (dol == 5) {
                _5++;
            } else if (dol == 10) {
                if (_5 > 0) {
                    _5--;
                    _10++;
                } else {
                    return false;
                }
            } else if (dol == 20) {
                if (_10 > 0 && _5 > 0) {
                    _10--;
                    _5--;
                } else if (_5 >= 3) {
                    _5 -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
#ifndef __ONLINE_JUDGE__
int main() {
    Solution s;
    vector<int> bills = {5, 5, 5, 5, 10, 5, 10, 10, 10, 20};
    bool res = s.lemonadeChange(bills);
    cout << res << endl;
    return 0;
}
#endif