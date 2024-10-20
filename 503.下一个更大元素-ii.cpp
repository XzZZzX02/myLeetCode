/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        vector<int> res(nums.size(), -1);
        stack<int> s;
        s.push(0);
        int n = nums.size();
        nums.resize(2 * n - 1);
        for (int i = 0; i < n - 1; i++) {
            nums[i + n] = nums[i];
        }
        for (int i = 1; i < nums.size(); i++) {
            while (!s.empty() && nums[i] > nums[s.top()]) {
                if (s.top() < n) {
                    res[s.top()] = nums[i];
                }
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};
// @lc code=end

// test case
int main() {
    vector<int> nums = {1, 2, 1};
    Solution sol;
    vector<int> res = sol.nextGreaterElements(nums);
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}