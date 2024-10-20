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
        int n = nums.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for (int i = 2 * n - 1;i >= 0; i--){
            int x = nums[i % n];
            while (!st.empty() && x >= st.top()){
                st.pop();
            }
            if (i < n && !st.empty()){
                ans[i] = st.top();
            }
            st.push(x);
        }
        return ans;
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