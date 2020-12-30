//
// Created by zhengxiaojian on 2020/12/29.
//

#ifndef CPP_147_H
#define CPP_147_H

#include "../../lib/ListNode.h"

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;

        auto *dummy = new ListNode();
        dummy->next = head;
        auto *cur = head->next;
        head->next = nullptr;

        while (cur != nullptr) {
            auto *p = dummy;
            while (p->next != nullptr && p->next->val < cur->val) p = p->next;
            auto *next = cur->next;
            cur->next = p->next;
            p->next = cur;
            cur = next;
        }

        return dummy->next;
    }
};

#endif //CPP_147_H
