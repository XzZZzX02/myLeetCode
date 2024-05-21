/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */
#include "leetcode.h"
// @lc code=start
class Solution {
    vector<vector<string>> res1;
    vector<string> subs;

public:
    bool isPalindromeNumber(string const& s) {
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - i - 1]) {
                return false;
            }
        }
        return true;
    }
    void isAllPalindrome(vector<vector<string>>& res,
                         vector<vector<string>>& res1) {
        for (auto v : res1) {
            bool flag = true;
            for (auto s : v) {
                if (!isPalindromeNumber(s)) {
                    flag = false;
                }
            }
            if (flag) {
                res.push_back(v);
            }
        }
    }
    void backtracing(const string& s, int start) {
        if (start >= s.size()) {
            res1.push_back(subs);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            string sub = s.substr(start, i - start + 1);
            subs.push_back(sub);
            backtracing(s, i + 1);
            subs.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        res1.clear();
        subs.clear();
        vector<vector<string>> res;
        backtracing(s, 0);
        isAllPalindrome(res, res1);
        return res;
    }
};
// @lc code=end
