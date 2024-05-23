/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (s.empty()) return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = 0;
        int k = g.size() - 1;
        int i = s.size() - 1;
        while (i >= 0 && k >= 0) {
            if (s[i] >= g[k]) {
                res++;
                i--;
            }
            k--;
        }
        return res;
    }
};
// @lc code=end
#ifndef __ONLINE_JUDGE__
int main() {
    Solution s;
    vector<int> g = {1, 2, 3};
    vector<int> si = {3};
    int res = s.findContentChildren(g, si);
    cout << res << endl;
    return 0;
}
#endif