//
// Created by zhengxiaojian on 2020/12/29.
//

#ifndef CPP_445_H
#define CPP_445_H

#include "../../lib/ListNode.h"
#include <string>

using namespace std;

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        string s1, s2;
        while (l1 != nullptr) {
            s1 += to_string(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            s2 += to_string(l2->val);
            l2 = l2->next;
        }

        int extra = 0;
        int i1 = s1.length() - 1;
        int i2 = s2.length() - 1;

        auto *dummy = new ListNode();
        while (i1 >= 0 || i2 >= 0 || extra > 0) {
            int s = (i1 >= 0 ? s1[i1] - '0' : 0) +
                    (i2 >= 0 ? s2[i2] - '0' : 0) +
                    extra;
            auto *t = new ListNode(s % 10);
            extra = s / 10;
            t->next = dummy->next;
            dummy->next = t;
            --i1;
            --i2;
        }

        return dummy->next;
    }
};

#endif //CPP_445_H
