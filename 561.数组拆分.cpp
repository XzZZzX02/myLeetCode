/*
 * @lc app=leetcode.cn id=561 lang=cpp
 *
 * [561] 数组拆分
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int res = 0;
        int minNum = *min_element(nums.begin(), nums.end());
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<int> count(maxNum - minNum + 1, 0);
        for (auto& num : nums) {
            count[num - minNum]++;
        }
        for (int i = 0; i < maxNum - minNum; i++) {
            count[i + 1] += count[i];
        }
        vector<int> sortedNums(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--) {
            sortedNums[count[nums[i] - minNum] - 1] = nums[i];
            count[nums[i] - minNum]--;
        }
        for (int i = 0; i <= nums.size() - 2; i += 2) {
            res += min(sortedNums[i], sortedNums[i + 1]);
        }
        return res;
    }
};
// @lc code=end
