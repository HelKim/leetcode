//
// Created by zhengxiaojian on 2020/12/28.
//

#ifndef CPP_25_H
#define CPP_25_H

#include "../../lib/ListNode.h"

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        auto *dummy = new ListNode();
        dummy->next = head;
        ListNode *pre = dummy;
        auto *start = head;
        auto *end = head;
        int i = 1;
        while (end != nullptr) {
            if (i++ != k) {
                end = end->next;
                continue;
            }

            auto end_next = end->next;

            reverse(start, end);
            pre->next = end;
            start->next = end_next;

            pre = start;
            start = end_next;
            end = start;
            i = 1;
        }

        return dummy->next;
    }

//    void reverse(ListNode *head, ListNode *end) {
//        if (head == end) return;
//
//        reverse(head->next, end);
//
//        head->next->next = head;
//        head->next = nullptr;
//    }

    void reverse(ListNode *head, ListNode *end) {
        ListNode *pre = nullptr;
        while (pre != end) {
            auto *t = head->next;
            head->next = pre;
            pre = head;
            head = t;
        }
    }
};
#endif //CPP_25_H
