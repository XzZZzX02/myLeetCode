/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) return {};
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        string key;
        for (string& s : strs) {
            key = s;
            sort(key.begin(), key.end());
            m[key].emplace_back(s);
        }
        for (auto [_, v] : m) {
            res.emplace_back(v);
        }
        return res;
    }
};
// @lc code=end
#ifndef __ONLINE_JUDGE__
int main() {
    Solution s;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = s.groupAnagrams(strs);
    for (auto& v : res) {
        for (auto& s : v) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}
#endif