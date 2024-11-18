/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff,
                                       int valueDiff) {
        int l = 0, r = 0, n = nums.size(), maxNum = nums[0], minNum = nums[0];
        for (int i = 0; i < n; i++) {
            maxNum = max(maxNum, nums[i]);
            minNum = min(minNum, nums[i]);
        }
        vector<int> buckets((maxNum - minNum) / (valueDiff + 1) + 3, 0);
        while (r < n) {
            int temp = (nums[r] - minNum) / (valueDiff + 1) + 1;
            buckets[temp]++;
            if (buckets[temp] > 1) {
                return true;
                break;
            } else if (valueDiff > 0 &&
                       (buckets[temp - 1] > 0 || buckets[temp + 1] > 0)) {
                for (int i = l; i < r; i++) {
                    if (abs(nums[r] - nums[i]) <= valueDiff) {
                        return true;
                        break;
                    }
                }
            }
            if (r - l >= indexDiff) {
                buckets[(nums[l++] - minNum) / (valueDiff + 1) + 1]--;
            }
            r++;
        }
        return false;
    }
};
// @lc code=end
