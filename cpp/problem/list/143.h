//
// Created by zhengxiaojian on 2020/12/28.
//

#ifndef CPP_143_H
#define CPP_143_H

#include "../../lib/ListNode.h"

class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return;

        auto *slow = head;
        auto *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        auto *tail = reverse(slow);

        auto *cur = new ListNode();
        while (head != nullptr && tail != nullptr && head != tail) {
            cur->next = head;
            auto *t = head->next;
            head->next = tail;
            head = t;
            tail = tail->next;
            cur = cur->next->next;
        }
    }

    ListNode *reverse(ListNode *head) {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur != nullptr) {
            auto *t = cur->next;
            cur->next = pre;
            pre = cur;
            cur = t;
        }
        return pre;
    }
};

#endif //CPP_143_H
