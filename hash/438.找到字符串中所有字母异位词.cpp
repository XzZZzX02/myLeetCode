/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int n = s.length(), m = p.length();
        int num = 0;
        if (n < m) {
            return res;
        }
        int count[26] = {0};
        for (char c : p) {
            count[c - 'a']++;
        }
        int i = 0;
        for (int j = 0; j < n; j++) {
            count[s[j] - 'a']--;
            while (count[s[j] - 'a'] < 0) {
                count[s[i] - 'a']++;
                i++;
            }
            if (j - i + 1 == m) {
                res.emplace_back(i);
            }
        }
        return res;
    }
};
// @lc code=end
