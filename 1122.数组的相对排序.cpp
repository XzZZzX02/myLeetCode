/*
 * @lc app=leetcode.cn id=1122 lang=cpp
 *
 * [1122] 数组的相对排序
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        unordered_map<int, int> umap{};
        for (int i = 0; i < arr1.size(); i++) {
            umap[arr1[i]]++;
        }
        int n = 0;
        for (auto& x : arr2) {
            while (umap[x]-- > 0) {
                res.push_back(x);
                n++;
            }
        }
        for (auto& [k, v] : umap) {
            while (v-- > 0) {
                res.push_back(k);
            }
        }
        sort(res.begin() + n, res.end());
        return res;
    }
};
// @lc code=end
