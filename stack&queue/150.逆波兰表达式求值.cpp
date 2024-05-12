/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        int res = 0;
        for (auto& token : tokens) {
            if (token == "+") {
                long long a = st.top();
                st.pop();
                long long b = st.top();
                st.pop();
                st.push(b + a);
            } else if (token == "-") {
                long long a = st.top();
                st.pop();
                long long b = st.top();
                st.pop();
                st.push(b - a);
            } else if (token == "*") {
                long long a = st.top();
                st.pop();
                long long b = st.top();
                st.pop();
                st.push(b * a);
            } else if (token == "/") {
                long long a = st.top();
                st.pop();
                long long b = st.top();
                st.pop();
                st.push(b / a);
            } else {
                st.push(stoll(token));
            }
        }
        return st.top();
    }
};
// @lc code=end
