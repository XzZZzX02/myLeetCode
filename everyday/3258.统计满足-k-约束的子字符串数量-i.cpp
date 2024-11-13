/*
 * @lc app=leetcode.cn id=3258 lang=cpp
 *
 * [3258] 统计满足 K 约束的子字符串数量 I
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int res = 0, l = 0, count[2]{};
        for (int i = 0; i < s.length(); i++) {
            count[s[i] & 1]++;
            while (count[0] > k && count[1] > k) {
                count[s[l] & 1]--;
                l++;
            }
            res += i - l + 1;
        }
        return res;
    }
};
// @lc code=end

