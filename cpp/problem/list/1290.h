//
// Created by zhengxiaojian on 2020/12/28.
//

#ifndef CPP_1290_H
#define CPP_1290_H

#include "../../lib/ListNode.h"

class Solution {
public:
    int getDecimalValue(ListNode *head) {
        int digit = 0;
        while (head != nullptr) {
            digit = digit * 2 + head->val;
            head = head->next;
        }
        return digit;
    }
};

#endif //CPP_1290_H
