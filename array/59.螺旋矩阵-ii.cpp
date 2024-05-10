/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */
#include "leetcode.h"
// @lc code=start
void changeCircle(vector<vector<int>> &matrix, int &num, int num_circle,
                  int &start_num) {
    int n = matrix.size();
    int m = matrix[0].size();
    if (num == 1) {
        matrix[n / 2][m / 2] = start_num;
        return;
    }
    if (num == 2) {
        matrix[n / 2 - 1][m / 2 - 1] = start_num++;
        matrix[n / 2 - 1][m / 2] = start_num++;
        matrix[n / 2][m / 2] = start_num++;
        matrix[n / 2][m / 2 - 1] = start_num++;
        return;
    }
    for (int i = num_circle - 1; i < m - num_circle; i++) {
        matrix[num_circle - 1][i] = start_num++;
    }
    for (int i = num_circle - 1; i < n - num_circle; i++) {
        matrix[i][m - num_circle] = start_num++;
    }
    for (int i = m - num_circle; i >= num_circle; i--) {
        matrix[n - num_circle][i] = start_num++;
    }
    for (int i = n - num_circle; i >= num_circle; i--) {
        matrix[i][num_circle - 1] = start_num++;
    }
    num -= 2;
    return changeCircle(matrix, num, num_circle + 1, start_num);
}
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int num = n;
        int start_num = 1;
        int num_circle = 1;
        changeCircle(matrix, num, num_circle, start_num);
        return matrix;
    }
};
// @lc code=end
#ifndef __ONLINE_JUDGE__
int main() {
    Solution s;
    vector<vector<int>> res;
    res = s.generateMatrix(2);
    for (auto i : res) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
#endif