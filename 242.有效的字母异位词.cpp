/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */
#include "leetcode.h"
// @lc code=start
int m[26] = {0};
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        memset(m, 0, sizeof(m));
        for (char c : s) {
            m[c - 'a']++;
        }
        for (char c : t) {
            m[c - 'a']--;
            if (m[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
