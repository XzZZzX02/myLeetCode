/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) {
            return true;
        }
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else if (c == ')' || c == ']' || c == '}') {
                if (st.empty()) {
                    return false;
                }
                char top = st.top();
                if (c == ')' && top == '(') {
                    st.pop();
                } else if (c == ']' && top == '[') {
                    st.pop();
                } else if (c == '}' && top == '{') {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
// @lc code=end
