/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        if (s.size() == 0) {
            return {};
        }
        int hash[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            hash[s[i] - 'a'] = i;
        }
        int left = 0, right = 0;
        vector<int> res;
        for (int i = 0; i < s.size(); i++) {
            right = max(right, hash[s[i] - 'a']);
            if (i == right) {
                res.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return res;
    }
};
// @lc code=end
#ifndef __ONLINE_JUDGE__
int main() {
    Solution s;
    string str = "ababcbacadefegdehijhklij";
    vector<int> res = s.partitionLabels(str);
    for (auto i : res) {
        cout << i << " " << endl;
    }
    return 0;
}
#endif