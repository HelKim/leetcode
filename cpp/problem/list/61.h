//
// Created by zhengxiaojian on 2020/12/28.
//

#ifndef CPP_61_H
#define CPP_61_H

#include "../../lib/ListNode.h"

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr) return head;

        int cnt = count(head);
        k %= cnt;

        if (k == 0) return head;

        auto *first = head;
        auto *second = head;
        while (k-- > 0) {
            first = first->next;
        }
        while (first->next != nullptr) {
            first = first->next;
            second = second->next;
        }

        auto *new_head = second->next;
        second->next = nullptr;
        first->next = head;

        return new_head;
    }

    int count(ListNode *head) {
        int n = 0;
        while (head != nullptr) {
            ++n;
            head = head->next;
        }
        return n;
    }
};

#endif //CPP_61_H
