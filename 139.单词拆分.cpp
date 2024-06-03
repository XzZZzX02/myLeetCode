/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    bool backtracking(const string& s, const unordered_set<string>& wordSet,
                      vector<bool>& used, int start) {
        if (start >= s.size()) {
            return true;
        }
        if (!used[start]) {
            return used[start];
        }
        for (int i = start; i < s.size(); i++) {
            string word = s.substr(start, i - start + 1);
            if (wordSet.find(word) != wordSet.end() &&
                backtracking(s, wordSet, used, i + 1)) {
                return true;
            }
        }
        used[start] = false;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> used(s.size(), true);
        return backtracking(s, wordSet, used, 0);
    }
};
// @lc code=end
