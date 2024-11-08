/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> res(score.size());
        vector<pair<int, int>> arr;
        vector<string> medal = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        int n = score.size();
        for (int i = 0; i < n; i++) {
            arr.push_back({-score[i], i});
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++) {
            if (i < 3) {
                res[arr[i].second] = medal[i];
            } else {
                res[arr[i].second] = to_string(i + 1);
            }
        }
        return res;
    }
};
// @lc code=end
