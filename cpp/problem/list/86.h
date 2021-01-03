//
// Created by zhengxiaojian on 2021/1/3.
//

#ifndef CPP_86_H
#define CPP_86_H

#include "../../lib/ListNode.h"

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (head == nullptr || head->next == nullptr) return head;

        auto *dummy1 = new ListNode();
        auto *dummy2 = new ListNode();
        auto *p1 = dummy1, *p2 = dummy2;

        while (head != nullptr) {
            if (head->val < x) {
                p1->next = head;
                p1 = p1->next;
            } else {
                p2->next = head;
                p2 = p2->next;
            }
            head = head->next;
        }

        p2->next = nullptr;
        p1->next = dummy2->next;

        return dummy1->next;
    }
};

#endif //CPP_86_H
