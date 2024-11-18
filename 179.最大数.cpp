/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;
        bool allZero = true;
        for (auto i : nums) {
            if (i != 0) {
                allZero = false;
                break;
            }
        }
        if (allZero) {
            return to_string(0);
        }
        vector<string> strNum(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            strNum[i] = to_string(nums[i]);
        }
        sort(strNum.begin(), strNum.end(),
             [](string& a, string& b) { return a + b > b + a; });
        for (int i = 0; i < strNum.size(); ++i) {
            res += strNum[i];
        }

        return res;
    }
};
// @lc code=end
