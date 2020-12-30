//
// Created by zhengxiaojian on 2020/12/28.
//

#ifndef CPP_92_H
#define CPP_92_H

#include "../../lib/ListNode.h"

class Solution {
public:
    ListNode *t;

    ListNode *reverseBetween(ListNode *head, int m, int n) {
        auto *dummy = new ListNode();
        dummy->next = head;
        auto pre = dummy;

        for (int i = 1; i < m; ++i) {
            pre = head;
            head = head->next;
        }

        pre->next = reverse(head, m, n);
        head->next = t;

        return dummy->next;
    }

    ListNode *reverse(ListNode *head, int cnt, int n) {
        if (cnt == n) {
            t = head->next;
            return head;
        }

        auto *tail = reverse(head->next, cnt + 1, n);

        head->next->next = head;
        head->next = nullptr;

        return tail;
    }
};
#endif //CPP_92_H
