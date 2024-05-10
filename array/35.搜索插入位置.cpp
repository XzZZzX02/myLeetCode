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
    int n = nums.size();
    int left = 0, right = n - 1;
    while (left <= right) {
      int mid = left + ((right - left) >> 1);
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return right + 1;
  }
};
// @lc code=end

#ifndef __ONLINE_JUDGE__
int main() {
  Solution s;
  vector<int> nums = {1, 3, 5, 6};
  int target = 7;
  int res = s.searchInsert(nums, target);
  cout << res << endl;
  return 0;
}
#endif