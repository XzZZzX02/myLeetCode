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
<<<<<<< HEAD
    void backtracing(vector<string>& res, string s, string digits, int start,
                     int n) {
=======
    void backtracking(vector<string>& res, string s, string digits, int start,
                      int n) {
>>>>>>> 675adc4 (17 1st 0ms backtracking)
        if (start == n) {
            if (!s.empty()) {
                res.push_back(s);
            }
            return;
        }
        string le = m[digits[start] - '0'];
        for (char l : le) {
            s.push_back(l);
<<<<<<< HEAD
            backtracing(res, s, digits, start + 1, n);
=======
            backtracking(res, s, digits, start + 1, n);
>>>>>>> 675adc4 (17 1st 0ms backtracking)
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        int n = digits.size();
        string t = "";
<<<<<<< HEAD
        backtracing(res, t, digits, 0, n);
=======
        backtracking(res, t, digits, 0, n);
>>>>>>> 675adc4 (17 1st 0ms backtracking)
        return res;
    }
};
// @lc code=end
