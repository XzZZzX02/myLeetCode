/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;

        int m = matrix.size();
        int n = matrix[0].size();
        int num = m * n;
        int start_num = 1;
        int num_circle = 1;
        while (num > 0) {
            for (int i = num_circle - 1; i < n - num_circle + 1 && num > 0;
                 i++) {
                result.push_back(matrix[num_circle - 1][i]);
                num--;
            }
            for (int i = num_circle; i < m - num_circle + 1 && num > 0; i++) {
                result.push_back(matrix[i][n - num_circle]);
                num--;
            }
            for (int i = n - num_circle - 1; i >= num_circle - 1 && num > 0;
                 i--) {
                result.push_back(matrix[m - num_circle][i]);
                num--;
            }
            for (int i = m - num_circle - 1; i >= num_circle && num > 0; i--) {
                result.push_back(matrix[i][num_circle - 1]);
                num--;
            }
            num_circle++;
        }
        return result;
    }
};
// @lc code=end
