//
// Created by zhengxiaojian on 2020/12/29.
//

#ifndef CPP_430_H
#define CPP_430_H

class Node {
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution {
public:
    Node *flatten(Node *head) {
        if (head == nullptr) return head;
        auto *child = flatten(head->child);
        auto *next = flatten(head->next);

        head->next = child;
        if (child != nullptr)
            child->prev = head;

        auto *cur = head;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = next;
        if (next != nullptr)
            next->prev = cur;

        head->child = nullptr;
        return head;
    }
};

#endif //CPP_430_H
