/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include "leetcode.h"
// @lc code=start
class Solution {
    vector<string> m = {"",    "",    "abc",  "def", "ghi",
                        "jkl", "mno", "pqrs", "tuv", "wxyz"};

public:
    void backtracing(vector<string>& res, string s, string digits, int start,
                     int n) {
        if (start == n) {
            if (!s.empty()) {
                res.push_back(s);
            }
            return;
        }
        string le = m[digits[start] - '0'];
        for (char l : le) {
            s.push_back(l);
            backtracing(res, s, digits, start + 1, n);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        int n = digits.size();
        string t = "";
        backtracing(res, t, digits, 0, n);
        return res;
    }
};
// @lc code=end
