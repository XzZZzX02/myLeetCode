/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */
#include <vector>

#include "leetcode.h"
// @lc code=start
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff,
                                       int valueDiff) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i - 1; j >= 0 && i - j <= indexDiff; j--) {
                if (abs((long long)nums[i] - (long long)nums[j]) <= valueDiff) {
                    return true;
                }
            }
            for (int j = i + 1; j < nums.size() && j - i <= indexDiff; j++) {
                if (abs((long long)nums[i] - (long long)nums[j]) <= valueDiff) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
