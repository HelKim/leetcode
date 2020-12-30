//
// Created by zhengxiaojian on 2020/12/28.
//

#ifndef CPP_160_2_H
#define CPP_160_2_H

#include "../../lib/ListNode.h"

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;

        ListNode *a = headA;
        ListNode *b = headB;

        while (a != b) {
            a = a == nullptr ? headB : a->next;
            b = b == nullptr ? headA : b->next;
        }

        return a;
    }
};

#endif //CPP_160_2_H
