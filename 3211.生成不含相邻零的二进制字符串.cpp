/*
 * @lc app=leetcode.cn id=3211 lang=cpp
 *
 * [3211] 生成不含相邻零的二进制字符串
 */
#include "leetcode.h"
// @lc code=start
class Solution {
    string t;
public:
    vector<string> validStrings(int n) {
        vector<string> res;
        dfs(0, n, res);
        return res;
    }

    void dfs(int i, int& n, vector<string>& res) {
        if (i >= n) {
            res.push_back(t);
            return;
        }
        for (int j = 0; j < 2; j++) {
            if ((j == 0 && (i == 0 || t[i - 1] == '1')) || j == 1) {
                t.push_back('0' + j);
                dfs(i + 1, n, res);
                t.pop_back();
            }
        }
    }
};
// @lc code=end

