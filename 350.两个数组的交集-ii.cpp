/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */
#include <algorithm>
#include <unordered_map>

#include "leetcode.h"
// @lc code=start
class Solution {
public:
    void insertRes(vector<int>& res, unordered_map<int, int> map1,
                   unordered_map<int, int> map2) {
        for (auto it1 = map1.begin(); it1 != map1.end(); it1++) {
            auto it2 = map2.find(it1->first);
            if (it2 != map2.end() && it1->second > 0 && it2->second > 0) {
                int count = min(it1->second, it2->second);
                res.insert(res.end(), count, it1->first);
            }
        }
    }
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map1, map2;
        vector<int> res;
        for (int num : nums1) {
            map1[num]++;
        }
        for (int num : nums2) {
            map2[num]++;
        }
        if (map1.size() > map2.size()) {
            insertRes(res, map1, map2);
        } else {
            insertRes(res, map2, map1);
        }
        return res;
    }
};
// @lc code=end
