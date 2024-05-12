/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include "leetcode.h"
// @lc code=start
class Solution {
    enum Direction { INCREASE = -1, DECREASE = 1 };

    template <typename T>
    class MonotonicQueue {
    private:
        std::deque<T> dq;
        Direction direction;

    public:
        MonotonicQueue(Direction dir = INCREASE) : direction(dir) {}

        void pop(T val) {
            if (!dq.empty() && dq.front() == val) {
                dq.pop_front();
            }
        }

        void push(T val) {
            while (!dq.empty() && (val - dq.back()) * direction < 0) {
                dq.pop_back();
            }
            dq.push_back(val);
        }

        T front() { return dq.front(); }
    };

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue<int> m_q;
        vector<int> res;
        for (int i = 0; i < k; i++) {
            m_q.push(nums[i]);
        }
        res.push_back(m_q.front());
        for (int i = k; i < nums.size(); i++) {
            m_q.pop(nums[i - k]);
            m_q.push(nums[i]);
            res.push_back(m_q.front());
        }
        return res;
    }
};
// @lc code=end
