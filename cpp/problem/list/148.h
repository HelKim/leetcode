//
// Created by zhengxiaojian on 2020/12/29.
//

#ifndef CPP_148_H
#define CPP_148_H

#include "../../lib/ListNode.h"

// 自顶向下的归并排序，时间复杂度O(nlogn)，空间复杂度O(logn)
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        return sortList(head, nullptr);
    }

    ListNode *sortList(ListNode *head, ListNode *tail) {
        if (head == nullptr) return head;
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }

        auto *slow = head;
        auto *fast = head;
        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }

        auto *mid = slow;

        auto *left = sortList(head, mid);
        auto *right = sortList(mid, tail);

        return merge(left, right);
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

#endif //CPP_148_H
