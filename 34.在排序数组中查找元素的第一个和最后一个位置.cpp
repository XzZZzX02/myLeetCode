/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    int last = -1;
    vector<int> res = {-1, -1};
    for (int i = 0; i <= right; i++) {
      if (nums[i] == target) {
        if (last == -1) {
          res[0] = i;
          res[1] = i;
          last = i;
        } else {
          res[1] = i;
        }
      }
    }
    return res;
  }
};
// @lc code=end
#ifndef __ONLINE_JUDGE__
int main() {
  Solution s;
  vector<int> nums = {5, 7, 7, 8, 8, 10};
  int target = 8;
  vector<int> res = s.searchRange(nums, target);
  for (int i : res) {
    cout << i << " ";
  }
  return 0;
}
#endif