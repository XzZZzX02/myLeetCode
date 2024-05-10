/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        int map[26] = {0};
        for (char c : magazine) {
            map[c - 'a']++;
        }
        for (char c : ransomNote) {
            if (map[c - 'a'] == 0) {
                return false;
            }
            map[c - 'a']--;
        }
        return true;
    }
};
// @lc code=end
