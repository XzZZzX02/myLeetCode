/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        int i = 0, count = 0, min_len = INT_MAX, min_start = 0;
        int t_map[128] = {0}, sub_map[128] = {0};
        for (char c : t) {
            t_map[c]++;
        }
        for (int j = 0; j < s.size(); j++) {
            char c = s[j];
            sub_map[c]++;
            if (t_map[c] > 0 && t_map[c] >= sub_map[c]) {
                count++;
            }
            while (count == t.size()) {
                if (j - i + 1 < min_len) {
                    min_len = j - i + 1;
                    min_start = i;
                }
                char d = s[i];
                if (t_map[d] > 0 && t_map[d] >= sub_map[d]) {
                    count--;
                }
                sub_map[d]--;
                i++;
            }
        }
        return min_len == INT_MAX ? "" : s.substr(min_start, min_len);
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