/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    int mid = 0;
    int res = -1;
    while (left <= right) {
      if (left == right) {
        if (nums[left] >= target) {
          res = left;
          break;
        } else {
          res = left + 1;
          break;
        }
      }
      mid = (left + right) / 2;
      if (nums[mid] == target) {
        res = mid;
        break;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    if (res == -1) {
      res = mid;
    }
    return res;
  }
};
// @lc code=end

#ifndef __ONLINE_JUDGE__
int main() {
  Solution s;
  vector<int> nums = {1, 3, 5, 6};
  int target = 3;
  int res = s.searchInsert(nums, target);
  cout << res << endl;
  return 0;
}
#endif