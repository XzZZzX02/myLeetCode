/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include <string>
#include <unordered_map>

#include "leetcode.h"
// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        string res(100001, '0');
        bool flag = false;
        unordered_map<char, int> map{};
        for (int i = 0; i < s.size(); i++) {
            for (int j = i + 1; j <= s.size(); j++) {
                flag = true;
                string sub = s.substr(i, j - i);
                map.clear();
                for (char c : t) {
                    map[c]++;
                }
                for (char c : sub) {
                    map[c]--;
                }
                for (auto it : map) {
                    if (it.second > 0) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    if (j - i < res.size()) {
                        res = s.substr(i, j - i);
                    }
                }
            }
        }
        return res.size() == 100001 ? "" : res;
    }
};
// @lc code=end
#ifndef __ONLINE_JUDGE__
int main() {
    Solution s;
    string s1 = "s";
    string t1 = "ss";
    string res = s.minWindow(s1, t1);
    cout << res << endl;
    return 0;
}
#endif