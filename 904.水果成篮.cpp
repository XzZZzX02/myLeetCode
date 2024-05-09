/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */
#include <unordered_map>

#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int res = 0;
        int i = 0;
        int j = 0;
        unordered_map<int, int> map{};
        for (j = 0; j < fruits.size(); j++) {
            map[fruits[j]]++;
            while (map.size() > 2) {
                // res = res > j - i + 1 ? res : j - i + 1;
                map[fruits[i]]--;
                if (map[fruits[i]] == 0) {
                    map.erase(fruits[i]);
                }
                i++;
            }
            res = res > j - i + 1 ? res : j - i + 1;
        }
        return res;
    }
};
// @lc code=end
#ifndef __ONLINE_JUDGE__
int main() {
    Solution s;
    vector<int> fruits = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    int res = s.totalFruit(fruits);
    cout << res << endl;
    return 0;
}
#endif