/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    void removeSpaces(string& s) {
        int n = s.size();
        int slow = 0, fast = 0;
        while (n > 0 && fast < n && s[fast] == ' ') {
            fast++;
        }
        for (; fast < n; fast++) {
            if (fast > 1 && s[fast] == ' ' && s[fast] == s[fast - 1]) {
                continue;
            } else {
                s[slow++] = s[fast];
            }
        }
        if (slow > 1 && s[slow - 1] == ' ') {
            s.resize(slow - 1);
        } else {
            s.resize(slow);
        }
    }
    string reverseWords(string s) {
        removeSpaces(s);
        reverse(s.begin(), s.end());
        int start = 0, end = 0;
        int n = s.size();
        auto it_begin = s.begin();
        while (end < n) {
            while (s[end] != ' ' && end < n) {
                end++;
            };
            reverse(it_begin + start, it_begin + end);
            start = end + 1;
            end = start + 1;
        }
        return s;
    }
};
// @lc code=end
