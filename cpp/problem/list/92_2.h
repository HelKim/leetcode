//
// Created by zhengxiaojian on 2020/12/28.
//

#ifndef CPP_92_2_H
#define CPP_92_2_H

#include "../../lib/ListNode.h"

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        auto *dummy = new ListNode();
        dummy->next = head;
        auto pre = dummy;

        for (int i = 1; i < m; ++i) {
            pre = head;
            head = head->next;
        }

        auto cur = head;
        auto *prev = pre;

        while (m++ <= n) {
            auto *t = cur->next;
            cur->next = prev;
            prev = cur;
            cur = t;
        }

        pre->next = prev;
        head->next = cur;
        return dummy->next;
    }
};

#endif //CPP_92_2_H
