#ifndef __MONOTONIC_QUEUE_H__
#define __MONOTONIC_QUEUE_H__

#include <deque>

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
#endif