/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */
#include "leetcode.h"
// @lc code=start
class Solution {
    void countingsort(vector<int>& v, int m, int n) {
        vector<int> count(m - n + 1, 0);
        for (int i = 0; i < v.size(); i++) {
            count[v[i] - n]++;
        }
        int j = 0;
        for (int i = 0; i < m - n + 1; i++) {
            while (count[i] != 0) {
                v[j] = i + n;
                j++;
                count[i]--;
            }
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        int min = 100;
        int max = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (min > nums[i]) {
                min = nums[i];
            }
            if (max < nums[i]) {
                max = nums[i];
            }
        }
        countingsort(nums, max, min);
        return nums;
    }
};
// @lc code=end

int main() {
    Solution sol;
    vector<int> nums = {5, 2, 3, 1};
    vector<int> res = sol.sortArray(nums);
    return 0;
}