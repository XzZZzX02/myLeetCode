/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */
#include "leetcode.h"
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) {
            return nullptr;
        }
        while (head->val == val) {
            head = head->next;
            if (!head) {
                return nullptr;
            }
        }

        ListNode* cur = head;
        while (cur->next && cur) {
            if (cur->next->val == val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};
// @lc code=end
#ifndef __ONLINE_JUDGE__
int main() {
    Solution s;
    ListNode* head =
        new ListNode(7, new ListNode(7, new ListNode(7, new ListNode(7))));
    ListNode* res = s.removeElements(head, 7);
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << res << endl;
    return 0;
}
#endif