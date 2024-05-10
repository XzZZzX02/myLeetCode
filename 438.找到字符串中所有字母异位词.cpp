/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */
#include <cstring>

#include "leetcode.h"
// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int n = s.length(), m = p.length();
        if (n < m) {
            return res;
        }
        int count[26] = {0};
        for (char c : p) {
            count[c - 'a']++;
        }
        int count_p[26];
        for (int i = 0; i < n - m + 1; i++) {
            bool flag = true;
            for (int j = i; j < i + m; j++) {
                count_p[s[j] - 'a']--;
                if (count_p[s[j] - 'a'] < 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res.emplace_back(i);
            }
        }
        return res;
    }
};
// @lc code=end
