/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        if (s.empty()) {
            return 0;
        }
        string t = "^#";
        for (auto c : s) {
            t += c;
            t += '#';
        }
        t += '$';
        int n = t.size();
        vector<int> p(n, 0);
        int pos = 0, maxRight = 0, res = 0;
        for (int i = 1; i < n - 1; i++) {
            p[i] = i < maxRight ? min(p[2 * pos - i], maxRight - i) : 1;
            while (t[i + p[i]] == t[i - p[i]]) {
                p[i]++;
            }
            if (i + p[i] > maxRight) {
                maxRight = i + p[i];
                pos = i;
            }
            res += p[i] / 2;
        }
        return res;
    }
};
// @lc code=end

