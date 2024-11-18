/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */
#include "leetcode.h"
// @lc code=start
class Solution {
    vector<int> __nums;
    int n;

public:
    Solution(vector<int>& nums) {
        __nums = nums;
        n = nums.size();
    }

    vector<int> reset() { return __nums; }

    vector<int> shuffle() {
        vector<int> res = __nums;
        for (int i = 0; i < n; i++) {
            int j = rand() % (n - i) + i;
            swap(res[i], res[j]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end
