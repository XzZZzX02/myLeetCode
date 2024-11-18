/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> paths;
        string res, s;
        int i = 1;
        for (int j = 1; j <= path.length(); j++) {
            if (path[j] == '/' || j == path.length()) {
                if (path[j - 1] == '/') {
                    i++;
                    continue;
                }
                s = path.substr(i, j - i);
                i = j + 1;
                if (s == "..") {
                    if (!paths.empty()) {
                        paths.pop();
                    }
                } else if (s != ".") {
                    paths.push(s);
                }
            }
        }
        while (!paths.empty()) {
            res = "/" + paths.top() + res;
            paths.pop();
        }
        return res.empty() ? "/" : res;
    }
};
// @lc code=end
