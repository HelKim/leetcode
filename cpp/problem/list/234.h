//
// Created by zhengxiaojian on 2020/12/28.
//

#ifndef CPP_234_H
#define CPP_234_H

#include "../../lib/ListNode.h"

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        if (head == nullptr) return true;

        auto *slow = head;
        auto *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        auto *tail = reverse(slow);

        while (head != nullptr && tail != nullptr) {
            if (head->val != tail->val) return false;
            head = head->next;
            tail = tail->next;
        }

        return true;
    }

    ListNode *reverse(ListNode *head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;

        auto *new_head = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;

        return new_head;
    }
};

#endif //CPP_234_H
