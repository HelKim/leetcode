//
// Created by zhengxiaojian on 2020/12/28.
//

#ifndef CPP_206_H
#define CPP_206_H

#include "../../lib/ListNode.h"

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;

        ListNode *h = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return h;
    }
};

#endif //CPP_206_H
