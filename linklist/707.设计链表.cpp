/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */
#include "leetcode.h"
// @lc code=start
class MyLinkedList {
public:
    int val, size;
    MyLinkedList* next;
    MyLinkedList* head;
    MyLinkedList() {
        head = nullptr;
        size = 0;
        next = nullptr;
    }

    MyLinkedList(int val) {
        this->val = val;
        this->next = nullptr;
    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;
        MyLinkedList* cur = head;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        MyLinkedList* newHead = new MyLinkedList(val);
        newHead->next = head;
        head = newHead;
        size++;
    }

    void addAtTail(int val) {
        MyLinkedList* cur = head;
        if (cur == nullptr) {
            head = new MyLinkedList(val);
            size++;
            return;
        }
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = new MyLinkedList(val);
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if (index == size) {
            addAtTail(val);
            return;
        }
        MyLinkedList* cur = head;
        for (int i = 0; i < index - 1; i++) {
            cur = cur->next;
        }
        MyLinkedList* newNode = new MyLinkedList(val);
        newNode->next = cur->next;
        cur->next = newNode;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        if (index == 0) {
            head = head->next;
            size--;
            return;
        }
        MyLinkedList* cur = head;
        for (int i = 0; i < index - 1; i++) {
            cur = cur->next;
        }
        cur->next = cur->next->next;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
