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
    for (int i = 0; i < n; ++i) {
      if (nums[i] >= target) {
        return i;
      }
    }
    return n;
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