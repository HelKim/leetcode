//
// Created by zhengxiaojian on 2020/12/30.
//

#ifndef CPP_707_H
#define CPP_707_H

struct LinkedListNode {
    int val;
    LinkedListNode *next;

    LinkedListNode() = default;

    LinkedListNode(int val) {
        this->val = val;
    }
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    LinkedListNode *head;
    LinkedListNode *tail;
    int count;

    MyLinkedList() {
        count = 0;
        head = new LinkedListNode();
        tail = nullptr;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= count) return -1;
        auto *cur = head;
        while (index-- >= 0) {
            cur = cur->next;
        }

        return cur->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        addAtIndex(count, val);
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > count) return;
        auto *cur = head;
        for (int i = 0; i < index; ++i) {
            cur = cur->next;
        }
        auto *node = new LinkedListNode(val);
        node->next = cur->next;
        cur->next = node;
        if (index == count) tail = node;
        ++count;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= count) return;
        auto *cur = head;
        for (int i = 0; i < index; ++i) {
            cur = cur->next;
        }
        cur->next = cur->next->next;
        --count;
        if (index == count) {
            tail = cur->next;
        }
    }
};

#endif //CPP_707_H
