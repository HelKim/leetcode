//
// Created by zhengxiaojian on 2020/12/28.
//

#ifndef CPP_206_2_H
#define CPP_206_2_H

#include "../../lib/ListNode.h"

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *pre = nullptr;
        auto *cur = head;

        while (cur != nullptr) {
            auto *t = cur->next;
            cur->next = pre;
            pre = cur;
            cur = t;
        }

        return pre;
    }
};

#endif //CPP_206_2_H
