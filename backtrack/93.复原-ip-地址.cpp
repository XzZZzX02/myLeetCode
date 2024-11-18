/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */
#include "leetcode.h"
// @lc code=start
class Solution {
    vector<string> res;

public:
    bool isValid(string const& s, int start, int end) {
        if (start > end) {
            return false;
        }
        if (s[start] == '0' && start != end) {
            return false;
        }
        int num = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] > '9' || s[i] < '0') {
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if (num > 255) {
                return false;
            }
        }
        return true;
    }
    void backtracking(string s, int start, int point_num) {
        int n = s.size();
        if (point_num == 3) {
            if (isValid(s, start, n - 1)) {
                res.push_back(s);
            }
            return;
        }
        for (int i = start; i < n; i++) {
            if (isValid(s, start, i)) {
                s.insert(s.begin() + i + 1, '.');
                point_num++;
                backtracking(s, i + 2, point_num);
                point_num--;
                s.erase(s.begin() + i + 1);
            } else
                break;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        res.clear();
        if (s.size() < 4 || s.size() > 12) return res;
        backtracking(s, 0, 0);
        return res;
    }
};
// @lc code=end
