//
// Created by zhengxiaojian on 2020/12/28.
//

#ifndef CPP_203_H
#define CPP_203_H

#include "../../lib/ListNode.h"

class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        auto *dummy = new ListNode();
        dummy->next = head;
        auto *pre = dummy;

        while (head != nullptr) {
            if (head->val == val) {
                pre->next = head->next;
                head = head->next;
                continue;
            }
            pre = head;
            head = head->next;
        }

        return dummy->next;
    }
};

#endif //CPP_203_H
