/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > target && nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] > target && nums[i] + nums[j] > 0) {
                    break;
                }
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int left = j + 1, right = n - 1;
                long sum1 = nums[i] + nums[j];
                long sum2 = target - sum1;
                while (left < right) {
                    if ((long)nums[left] + nums[right] == sum2) {
                        res.push_back(
                            {nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        while (left < right && nums[right] == nums[right - 1])
                            right--;
                        left++;
                        right--;
                    } else if ((long)nums[left] + nums[right] < sum2) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
