/*
 * @lc app=leetcode.cn id=498 lang=cpp
 *
 * [498] 对角线遍历
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res, t;
        int m = mat.size(), n = mat[0].size();
        for (int k = 0; k < m + n - 1; k++) {
            int i = k < n ? 0 : k - n + 1;
            int j = k < n ? k : n - 1;
            while (i < m && j >= 0) {
                t.push_back(mat[i++][j--]);
            }
            if (k % 2 == 0) {
                res.insert(res.end(), t.rbegin(), t.rend());
            } else {
                res.insert(res.end(), t.begin(), t.end());
            }
            t.clear();
        }
        return res;
    }
};
// @lc code=end

