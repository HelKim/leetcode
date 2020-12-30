//
// Created by zhengxiaojian on 2020/12/29.
//

#ifndef CPP_148_2_H
#define CPP_148_2_H

#include "../../lib/ListNode.h"

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;

        int length = 0;
        auto *node = head;
        while (node != nullptr) {
            node = node->next;
            ++length;
        }

        auto *dummy = new ListNode(0, head);

        for (int subLength = 1; subLength < length; subLength <<= 1) {
            ListNode *pre = dummy;
            ListNode *cur = dummy->next;

            while (cur != nullptr) {
                ListNode *head1 = cur;
                for (int i = 1; i < subLength && cur->next != nullptr; ++i) {
                    cur = cur->next;
                }
                ListNode *head2 = cur->next;
                cur->next = nullptr;

                cur = head2;
                for (int i = 1; i < subLength && cur != nullptr && cur->next != nullptr; ++i) {
                    cur = cur->next;
                }

                ListNode *next = nullptr;
                if (cur != nullptr) {
                    next = cur->next;
                    cur->next = nullptr;
                }

                auto *m = merge(head1, head2);
                pre->next = m;

                while (pre->next != nullptr) pre = pre->next;

                cur = next;
            }
        }
        return dummy->next;
    }

    ListNode *merge(ListNode *head1, ListNode *head2) {
        auto *dummy = new ListNode();
        auto cur = dummy;

        while (head1 != nullptr && head2 != nullptr) {
            if (head1->val <= head2->val) {
                cur->next = head1;
                head1 = head1->next;
            } else {
                cur->next = head2;
                head2 = head2->next;
            }
            cur = cur->next;
        }
        if (head1 != nullptr) cur->next = head1;
        if (head2 != nullptr) cur->next = head2;

        return dummy->next;
    }
};

#endif //CPP_148_2_H
