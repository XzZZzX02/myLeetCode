/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */
#include "leetcode.h"
// @lc code=start
class Solution {
    vector<vector<string>> res;
    vector<string> subs;
    vector<vector<bool>> isPalindrome;

public:
    void isPalindromeNumber(string const& s) {
        int n = s.size();
        isPalindrome.resize(s.size(), vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j) {
                    isPalindrome[i][j] = true;
                } else if (j - i == 1) {
                    isPalindrome[i][j] = s[i] == s[j];
                } else {
                    isPalindrome[i][j] =
                        s[i] == s[j] && isPalindrome[i + 1][j - 1];
                }
            }
        }
    }
    void backtracking(const string& s, int start) {
        if (start >= s.size()) {
            res.push_back(subs);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (isPalindrome[start][i]) {
                string sub = s.substr(start, i - start + 1);
                subs.push_back(sub);
            } else {
                continue;
            }
            backtracking(s, i + 1);
            subs.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        res.clear();
        subs.clear();
        isPalindromeNumber(s);
        backtracking(s, 0);
        return res;
    }
};
// @lc code=end
