/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
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

    inline int kmp(std::string goal, std::string pattern) {
        std::vector<int> next(pattern.size(), 0);
        getNext(pattern, next);
        int i = 0, j = 0;
        while (i < goal.size() && j < pattern.size()) {
            if (goal[i] == pattern[j]) {
                i++;
                j++;
            } else if (j > 0) {
                j = next[j - 1];
            } else {
                i++;
            }
        }
        if (j == pattern.size()) {
            return i - j;
        }
        return -1;
    }
    int strStr(string haystack, string needle) { return kmp(haystack, needle); }
};
// @lc code=end
#ifndef __ONLINE_JUDGE__
int main() {
    Solution s;
    string haystack = "hello";
    string needle = "ll";
    int res = s.strStr(haystack, needle);
    cout << res << endl;
    return 0;
}
#endif
