//
// Created by zhengxiaojian on 2020/12/28.
//

#ifndef CPP_160_H
#define CPP_160_H

#include <unordered_set>
#include "../../lib/ListNode.h"

using namespace std;

class Solution {
public:

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;

        unordered_set<ListNode *> set;
        while (headA != nullptr) {
            set.insert(headA);
            headA = headA->next;
        }

        while (headB != nullptr) {
            if (set.count(headB)) return headB;
            headB = headB->next;
        }

        return nullptr;
    }
};

#endif //CPP_160_H
