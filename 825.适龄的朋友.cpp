/*
 * @lc app=leetcode.cn id=825 lang=cpp
 *
 * [825] 适龄的朋友
 */
#include <algorithm>

#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int res = 0;
        sort(ages.begin(), ages.end());
        for (int k = 0, i = 0, j = 0; k < ages.size(); k++) {
            while (i < k && !check(ages[i], ages[k])) {
                i++;
            }
            if (j < k) {
                j = k;
            }
            while (j < ages.size() && check(ages[j], ages[k])) {
                j++;
            }
            if (j > i) {
                res += j - i - 1;
            }
        }
        return res;
    }
    bool check(int x, int y) {
        if (y <= 0.5 * x + 7) {
            return false;
        }
        if (y > x) {
            return false;
        }
        if (y > 100 && x < 100) {
            return false;
        }
        return true;
    }
};
// @lc code=end
