//
// Created by zhengxiaojian on 2020/12/28.
//

#ifndef CPP_82_H
#define CPP_82_H

#include "../../lib/ListNode.h"


class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        auto dummy = new ListNode();
        dummy->next = head;
        ListNode *pre = dummy;
        ListNode *cur = head;

        while (cur != nullptr) {
            auto last = find_last_same(cur, cur->val);
            if (cur != last) {
                pre->next = last->next;
                cur = last->next;
                continue;
            }
            pre = cur;
            cur = cur->next;
        }

        return dummy->next;
    }

    ListNode *find_last_same(ListNode *head, int val) {
        auto pre = head;
        auto cur = head->next;

        while (cur != nullptr && cur->val == val) {
            pre = head;
            head = head->next;
        }

        return pre;
    }
};

#endif //CPP_82_H
