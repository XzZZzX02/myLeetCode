/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */
#include "leetcode.h"
// @lc code=start
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#define ALL(v) v.begin(), v.end()
#define For(i, _) for (int i = 0, i##end = _; i < i##end; ++i)       // [0,_)
#define FOR(i, _, __) for (int i = _, i##end = __; i < i##end; ++i)  // [_,__)
#define Rep(i, _) for (int i = (_) - 1; i >= 0; --i)                 // [0,_)
#define REP(i, _, __) \
    for (int i = (__) - 1, i##end = _; i >= i##end; --i)  // [_,__)
typedef long long ll;
typedef unsigned long long ull;
#define V vector
#define pb push_back
#define pf push_front
#define qb pop_back
#define qf pop_front
#define eb emplace_back
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
#define fi first
#define se second
const int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}, inf = 0x3f3f3f3f,
          mod = 1e9 + 7;
const ll infl = 0x3f3f3f3f3f3f3f3fll;
template <class T>
inline bool ckmin(T &x, const T &y) {
    return x > y ? x = y, 1 : 0;
}
template <class T>
inline bool ckmax(T &x, const T &y) {
    return x < y ? x = y, 1 : 0;
}
int init = []() { return cin.tie(nullptr)->sync_with_stdio(false), 0; }();
inline int lcs(const string &a, const string &b) {
    if (a.empty() || b.empty()) return 0;
    int n = a.size(), m = b.size(), k = (n + 62) / 63;
    V<ull> f(k);
    char mn = *min_element(ALL(a)), mx = *max_element(ALL(a));
    V<V<ull>> g(mx - mn + 1, V<ull>(k));
    For(i, n) g[a[i] - mn][i / 63] |= 1ull << i % 63;
    for (char i : b) {
        if (i < mn || i > mx) continue;
        i -= mn;
        ull z = 1;
        For(j, k) {
            ull x = f[j], y = f[j] | g[i][j];
            ((x <<= 1) |= z) += (~y) & ((1ull << 63) - 1);
            f[j] = x & y, z = x >> 63;
        }
    }
    return accumulate(
        ALL(f), 0, [&](int x, ull y) { return x + __builtin_popcountll(y); });
}
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        return lcs(text1, text2);
    }
};
// @lc code=end
