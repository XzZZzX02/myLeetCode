/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); i++) {
            for (int j = i + 1; j < numbers.size(); j++) {
                if (numbers[i] + numbers[j] == target && i != j) {
                    return {i + 1, j + 1};
                }
            }
        }
        return {-1, -1};
    }
};
// @lc code=end
