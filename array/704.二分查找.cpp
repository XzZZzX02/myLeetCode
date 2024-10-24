/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
  int search(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    int mid = 0;
    while (left <= right) {
      mid = (left + right) >> 1;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] > target) {
        right = mid - 1;
      } else if (nums[mid] < target) {
        left = mid + 1;
      }
    }
    return -1;
  }
};
// @lc code=end
