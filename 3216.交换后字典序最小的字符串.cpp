/*
 * @lc app=leetcode.cn id=3216 lang=cpp
 *
 * [3216] 交换后字典序最小的字符串
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    string getSmallestString(string s) {
        if (s.empty()) {
            return s;
        }
        int n = s.size();
        for (int i = 1; i < n; i++) {
            auto a = s[i - 1], b = s[i];
            if (a > b && a % 2 == b % 2) {
                s[i - 1] = b;
                s[i] = a;
                break;
            }
        }
        return s;
    }
};
// @lc code=end

