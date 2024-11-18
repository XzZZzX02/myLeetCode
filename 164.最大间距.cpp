/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        int res = 0, n = nums.size(), prev = INT_MAX;
        vector<vector<int>> bucket(10, vector<int>());
        int maxNum = INT_MIN, minNum = INT_MAX;
        for (auto& nums : nums) {
            maxNum = max(maxNum, nums);
            minNum = min(minNum, nums);
        }
        int bucketSize = max(1, (maxNum - minNum) / (n - 1));
        int bucketNum = (maxNum - minNum) / bucketSize + 1;
        vector<pair<int, int>> buckets(bucketNum, {INT_MAX, INT_MIN});
        for (auto& num : nums) {
            int i = (num - minNum) / bucketSize;
            buckets[i].first = min(buckets[i].first, num);
            buckets[i].second = max(buckets[i].second, num);
        }
        for (auto& [curMin, curMax] : buckets) {
            if (curMin > curMax) {
                continue;
            }
            res = max(res, curMin - prev);
            prev = curMax;
        }
        return res;
    }
};
// @lc code=end
