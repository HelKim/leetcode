//
// Created by zhengxiaojian on 2020/12/30.
//

#ifndef CPP_0201_H
#define CPP_0201_H

#include "../../lib/ListNode.h"

class Solution {
public:
    ListNode *removeDuplicateNodes(ListNode *head) {
        auto *cur = head;
        while (cur != nullptr) {
            cur->next = remove(cur->next, cur->val);
            cur = cur->next;
        }
        return head;
    }

    ListNode *remove(ListNode *head, int val) {
        auto *dummy = new ListNode();
        dummy->next = head;
        auto *pre = dummy;
        auto *cur = head;

        while (cur != nullptr) {
            if (cur->val == val) {
                pre->next = cur->next;
                cur = cur->next;
                continue;
            }
            pre = cur;
            cur = cur->next;
        }

        return dummy->next;
    }
};

#endif //CPP_0201_H
