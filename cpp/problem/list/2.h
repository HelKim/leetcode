//
// Created by zhengxiaojian on 2020/12/28.
//

#ifndef CPP_2_H
#define CPP_2_H

#include "../../lib/ListNode.h"

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int extra = 0;
        auto *dummy = new ListNode();
        auto *head = dummy;
        while (l1 != nullptr || l2 != nullptr || extra != 0) {
            int s = (l1 != nullptr ? l1->val : 0) +
                    (l2 != nullptr ? l2->val : 0) +
                    extra;
            head->next = new ListNode(s % 10);
            extra = s / 10;
            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
            head = head->next;
        }
        return dummy->next;
    }
};

#endif //CPP_2_H
