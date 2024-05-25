/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        vector<vector<int>> res;
        if (intervals.empty()) {
            return res;
        } else if (intervals.size() == 1) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });
        int left = intervals[0][0], right = intervals[0][1];
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][0] <= right) {
                left = min(left, intervals[i][0]);
                right = max(right, intervals[i][1]);
            } else {
                res.push_back({left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        res.push_back({left, right});
        return res;
    }
};
// @lc code=end
#ifndef __ONLINE_JUDGE__
int main() {
    Solution s;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> res = s.merge(intervals);
    for (auto v : res) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
#endif