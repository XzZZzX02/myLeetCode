/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int back_s = 0, i_s = s.length() - 1;
        int back_t = 0, i_t = t.length() - 1;
        while (i_s >= 0 || i_t >= 0) {
            while (i_s >= 0) {
                if (s[i_s] == '#') {
                    back_s++;
                    i_s--;
                } else if (back_s > 0) {
                    back_s--;
                    i_s--;
                } else {
                    break;
                }
            }
            while (i_t >= 0) {
                if (t[i_t] == '#') {
                    back_t++;
                    i_t--;
                } else if (back_t > 0) {
                    back_t--;
                    i_t--;
                } else {
                    break;
                }
            }
            if (i_s >= 0 && i_t >= 0) {
                if (s[i_s] != t[i_t]) {
                    return false;
                }
            } else {
                if (i_s >= 0 || i_t >= 0) {
                    return false;
                }
            }
            i_s--;
            i_t--;
        }
        return true;
    }
};
// @lc code=end
