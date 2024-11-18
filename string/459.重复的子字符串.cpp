/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    inline void getNext(std::string pattern, std::vector<int>& next) {
        int j = 0;
        next[0] = j;
        for (int i = 1; i < pattern.size(); i++) {
            while (j > 0 && pattern[i] != pattern[j]) {
                j = next[j - 1];
            }
            if (pattern[i] == pattern[j]) {
                j++;
            }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        vector<int> next(n, 0);
        getNext(s, next);
        return n % (n - next[n - 1]) == 0 && next[n - 1] != 0;
    }
};
// @lc code=end
