#include <bits/stdc++.h>

#include "utils/kmp.h"
#include "utils/monotonic_queue.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Node {
public:
    int val;
    vector<Node *> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

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

    int lowbit(int x) { return x & -x; }
};

class UnionFind {
private:
    vector<int> p, size;

public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    int find(int x) {
        if (x != p[x]) {
            p[x] = find(p[x]);
        }
        return p[x];
    }
};

class NodeSegTree {
public:
    int l, r;
    long long s00, s01, s10, s11;

    NodeSegTree(int l, int r) : l(l), r(r), s00(0), s01(0), s10(0), s11(0) {}
};

class SegmentTree {
public:
    vector<NodeSegTree *> tr;

    SegmentTree(int n) : tr(n << 2) { build(1, 1, n); }

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
        NodeSegTree *left = tr[u << 1];
        NodeSegTree *right = tr[u << 1 | 1];
        tr[u]->s00 = max(left->s00 + right->s10, left->s01 + right->s00);
        tr[u]->s01 = max(left->s00 + right->s11, left->s01 + right->s01);
        tr[u]->s10 = max(left->s10 + right->s10, left->s11 + right->s00);
        tr[u]->s11 = max(left->s10 + right->s11, left->s11 + right->s01);
    }

    void modify(int u, int x, int v) {
        if (tr[u]->l == tr[u]->r) {
            tr[u]->s11 = max(0LL, (long long)v);
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
