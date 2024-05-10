#ifndef __KMP_H__
#define __KMP_H__

#include <string>
#include <vector>

void getNext(std::string pattern, std::vector<int>& next);
int kmp(std::string goal, std::string pattern);

inline void getNext(std::string pattern, std::vector<int>& next) {
    int j = 0;
    next[0] = j;
    for (int i = 1; i < pattern.size(); i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = next[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            j++;
        }
        next[i] = j;
    }
}

inline int kmp(std::string goal, std::string pattern) {
    std::vector<int> next(pattern.size(), 0);
    getNext(pattern, next);
    int i = 0, j = 0;
    while (i < goal.size() && j < pattern.size()) {
        if (goal[i] == pattern[j]) {
            i++;
            j++;
        } else if (j > 0) {
            j = next[j - 1];
        } else {
            i++;
        }
    }
    if (j == pattern.size()) {
        return i - j;
    }
    return -1;
}
#endif