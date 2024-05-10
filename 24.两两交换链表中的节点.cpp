/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* virtue = new ListNode(0);
        virtue->next = head;
        ListNode* cur = virtue;
        while (cur->next && cur->next->next) {
            ListNode* p = cur->next;
            ListNode* q = p->next->next;
            cur->next = cur->next->next;
            cur->next->next = p;
            cur->next->next->next = q;
            cur = cur->next->next;
        }
        ListNode* res = virtue->next;
        delete virtue;
        return res;
    }
};
// @lc code=end
