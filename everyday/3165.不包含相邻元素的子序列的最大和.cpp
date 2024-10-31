/*
 * @lc app=leetcode.cn id=3165 lang=cpp
 *
 * [3165] 不包含相邻元素的子序列的最大和
 */
#include "leetcode.h"
// @lc code=start
class NodeSegTree {
public:
    int l, r;
    long long s00, s01, s10, s11;

    NodeSegTree(int l, int r)
        : l(l)
        , r(r)
        , s00(0)
        , s01(0)
        , s10(0)
        , s11(0) {}
};

class SegmentTree {
public:
    vector<NodeSegTree*> tr;

    SegmentTree(int n)
        : tr(n << 2) {
        build(1, 1, n);
    }

    void build(int u, int l, int r) {
        tr[u] = new NodeSegTree(l, r);
        if (l == r) {
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }

    long long query(int u, int l, int r) {
        if (tr[u]->l >= l && tr[u]->r <= r) {
            return tr[u]->s11;
        }
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        long long ans = 0;
        if (r <= mid) {
            ans = query(u << 1, l, r);
        }
        if (l > mid) {
            ans = max(ans, query(u << 1 | 1, l, r));
        }
        return ans;
    }

    void pushup(int u) {
        NodeSegTree* left = tr[u << 1];
        NodeSegTree* right = tr[u << 1 | 1];
        tr[u]->s00 = max(left->s00 + right->s10, left->s01 + right->s00);
        tr[u]->s01 = max(left->s00 + right->s11, left->s01 + right->s01);
        tr[u]->s10 = max(left->s10 + right->s10, left->s11 + right->s00);
        tr[u]->s11 = max(left->s10 + right->s11, left->s11 + right->s01);
    }

    void modify(int u, int x, int v) {
        if (tr[u]->l == tr[u]->r) {
            tr[u]->s11 = max(0LL, (long long) v);
            return;
        }
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        if (x <= mid) {
            modify(u << 1, x, v);
        } else {
            modify(u << 1 | 1, x, v);
        }
        pushup(u);
    }

    ~SegmentTree() {
        for (auto node : tr) {
            delete node;
        }
    }
};

class Solution {
public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        SegmentTree tree(n);
        for (int i = 0; i < n; ++i) {
            tree.modify(1, i + 1, nums[i]);
        }
        long long ans = 0;
        const int mod = 1e9 + 7;
        for (const auto& q : queries) {
            tree.modify(1, q[0] + 1, q[1]);
            ans = (ans + tree.query(1, 1, n)) % mod;
        }
        return (int) ans;
    }
};
// @lc code=end

