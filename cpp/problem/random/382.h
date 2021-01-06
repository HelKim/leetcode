//
// Created by zhengxiaojian on 2021/1/6.
//

#ifndef CPP_382_H
#define CPP_382_H

#include "../../lib/ListNode.h"
#include <cstdlib>
#include <ctime>

class Solution {
public:
    ListNode *head;

    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode *head) {
        this->head = head;
        srand(time(nullptr));
    }

    /** Returns a random node's value. */
    int getRandom() {
        int i = 1;
        int select;
        auto *cur = head;
        while (cur != nullptr) {
            int r = rand() % i + 1;
            if (r == i) {
                select = cur->val;
            }
            cur = cur->next;
            ++i;
        }

        return select;
    }
};

#endif //CPP_382_H
