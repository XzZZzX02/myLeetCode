/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */
#include <algorithm>
#include <vector>
#include "leetcode.h"
// @lc code=start
class Solution {
    void countingsort(vector<int>& v, int m, int n) {
        vector<int> count(m - n + 1, 0);
        for (int i = 0; i < v.size(); i++) {
            count[v[i] - n]++;
        }
        int j = 0;
        for (int i = 0; i < m - n + 1; i++) {
            while (count[i] != 0) {
                v[j] = i + n;
                j++;
                count[i]--;
            }
        }
    }

    void insertionSort(vector<int>& v) {
        for (int i = 1; i < v.size(); i++) {
            int key = v[i];
            int j = i - 1;
            while (j >= 0 && v[j] > key) {
                v[j + 1] = v[j];
                j--;
            }
            v[j + 1] = key;
        }
    }

    void bucketSort(vector<int>& v, int bucketSize = 5) {
        int min = *min_element(v.begin(), v.end());
        int max = *max_element(v.begin(), v.end());
        int bucketCount = (max - min) / bucketSize + 1;
        vector<vector<int>> buckets(bucketCount);
        for (auto& x : v) {
            buckets[(x - min) / bucketSize].push_back(x);
        }
        v.clear();
        for (auto& bucket : buckets) {
            insertionSort(bucket);
            for (auto& x : bucket) {
                v.push_back(x);
            }
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        int min = 100;
        int max = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (min > nums[i]) {
                min = nums[i];
            }
            if (max < nums[i]) {
                max = nums[i];
            }
        }
        bucketSort(nums);
        return nums;
    }
};
// @lc code=end

int main() {
    Solution sol;
    vector<int> nums = {5, 2, 3, 1};
    vector<int> res = sol.sortArray(nums);
    return 0;
}