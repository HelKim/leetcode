//
// Created by zhengxiaojian on 2020/12/28.
//

#ifndef CPP_142_H
#define CPP_142_H

#include "../../lib/ListNode.h"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return head;

        auto *fast = head->next;
        auto *slow = head;

        while (fast != nullptr && fast->next != nullptr && fast != slow) {
            fast = fast->next->next;
            slow = slow->next;
        }

        if (fast == nullptr || fast->next == nullptr) return nullptr;

        slow = head;
        fast = fast->next;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};

#endif //CPP_142_H
