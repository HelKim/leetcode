//
// Created by zhengxiaojian on 2020/12/29.
//

#ifndef CPP_328_H
#define CPP_328_H

#include "../../lib/ListNode.h"

class Solution {
public:
    ListNode *oddEvenList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;

        auto *odd = new ListNode();
        auto *even = new ListNode();
        auto *op = odd;
        auto *ep = even;

        while (head != nullptr) {
            op->next = head;
            head = head->next;
            op = op->next;
            op->next = nullptr;

            if (head != nullptr) {
                ep->next = head;
                head = head->next;
                ep = ep->next;
                ep->next = nullptr;
            }
        }
        op->next = even->next;
        return odd->next;
    }
};

#endif //CPP_328_H
