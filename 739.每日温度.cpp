/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        if (temperatures.empty()) return {};
        stack<int> s;
        vector<int> res(temperatures.size(), 0);
        s.push(0);
        for (int i = 1; i < temperatures.size(); i++) {
            if (temperatures[i] <= temperatures[s.top()]) {
                s.push(i);
            } else {
                while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                    res[s.top()] = i - s.top();
                    s.pop();
                }
                s.push(i);
            }
        }
        return res;
    }
};
// @lc code=end

