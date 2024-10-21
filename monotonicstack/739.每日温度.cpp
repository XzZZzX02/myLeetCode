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
        vector<int> answer(temperatures.size());
        int maxT = 0;
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            if (maxT > temperatures[i]) {
                for (int j = i + 1; j < temperatures.size(); j++) {
                    if (temperatures[j] > temperatures[i]) {
                        answer[i] = j - i;
                        break;
                    } else {
                        j += answer[j];
                        j--;
                    }
                }
            } else {
                answer[i] = 0;
            }
            if (temperatures[i] > maxT) maxT = temperatures[i];
        }
        return answer;
    }
};
// @lc code=end
