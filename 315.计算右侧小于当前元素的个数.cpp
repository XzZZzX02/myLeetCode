/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */
#include "leetcode.h"
// @lc code=start
class Solution {
    class BinaryIndexedTree {
        vector<int> tree;
        int n;
    
    public:
        BinaryIndexedTree(int _n) : n(_n), tree(_n + 1) {}

        void update(int x, int delta) {
            while (x <= n) {
                tree[x] += delta;
                x += lowbit(x);
            }
        }

        int query(int x) {
            int sum = 0;
            while (x) {
                sum += tree[x];
                x -= lowbit(x);
            }
            return sum;
        }

        int lowbit(int x) {
            return x & -x;
        }
    };

public:
    vector<int> countSmaller(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        vector<int> all(s.begin(), s.end());
        sort(all.begin(), all.end());
        unordered_map<int, int> umap;
        int n = all.size();
        for (int i = 0; i < n; i++) {
            umap[all[i]] = i + 1;
        }
        BinaryIndexedTree bit(n);
        vector<int> res(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--) {
            int x = umap[nums[i]];
            res[i] = bit.query(x - 1);
            bit.update(x, 1);
        }
        return res;
    }
};
// @lc code=end

