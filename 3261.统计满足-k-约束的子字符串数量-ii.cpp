/*
 * @lc app=leetcode.cn id=3261 lang=cpp
 *
 * [3261] 统计满足 K 约束的子字符串数量 II
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k,
                                                 vector<vector<int>>& queries) {
        int n = s.size();
        vector<long long> res(queries.size());
        vector<long long> right(n, n);
        vector<long long> sum(n + 1, 0);
        int cnt[2]{}, l = 0;
        for (int i = 0; i < n; i++) {
            cnt[s[i] & 1]++;
            while (cnt[0] > k && cnt[1] > k) {
                right[l] = i;
                cnt[s[l] & 1]--;
                l++;
            }
            sum[i + 1] = sum[i] + i - l + 1;
        }
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0], r = queries[i][1];
            int j = fmin(right[l], r + 1);
            res[i] = sum[r + 1] - sum[j] + (long long)(j - l + 1) * (j - l) / 2;
        }
        return res;
    }
};
// @lc code=end
