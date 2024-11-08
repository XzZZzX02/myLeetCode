/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> res(score.size());
        vector<int> rank(score.size());
        rank = score;
        sort(rank.begin(), rank.end(), greater<int>());
        for (int i = 0; i < score.size(); i++) {
            for (int j = 0; j < rank.size(); j++) {
                if (score[i] == rank[j]) {
                    if (j == 0) {
                        res[i] = "Gold Medal";
                    } else if (j == 1) {
                        res[i] = "Silver Medal";
                    } else if (j == 2) {
                        res[i] = "Bronze Medal";
                    } else {
                        res[i] = to_string(j + 1);
                    }
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end
