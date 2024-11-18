/*
 * @lc app=leetcode.cn id=841 lang=cpp
 *
 * [841] 钥匙和房间
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int count = 0;
        vector<bool> visit(rooms.size(), false);
        dfs(rooms, visit, 0, count);
        return count == rooms.size();
    }

    void dfs(vector<vector<int>>& rooms, vector<bool>& visit, int i,
             int& count) {
        if (visit[i]) {
            return;
        }
        visit[i] = true;
        ++count;
        for (auto x : rooms[i]) {
            dfs(rooms, visit, x, count);
        }
    }
};
// @lc code=end
