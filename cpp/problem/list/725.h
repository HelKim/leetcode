//
// Created by zhengxiaojian on 2020/12/29.
//

#ifndef CPP_725_H
#define CPP_725_H

#include "../../lib/ListNode.h"
#include <vector>

using namespace std;

class Solution {
public:
    vector<ListNode *> splitListToParts(ListNode *root, int k) {
        vector<ListNode *> res(k);
        int n = count(root);
        int num = n / k;
        int extra = n % k;
        auto *d = new ListNode();
        for (int i = 0; i < k; ++i) {
            auto *dummy = d;
            dummy->next = nullptr;
            res[i] = dummy;
            int c = num + (i + 1 <= extra ? 1 : 0);
            while (c-- > 0 && root != nullptr) {
                dummy->next = root;
                root = root->next;
                dummy->next->next = nullptr;
                dummy = dummy->next;
            }
            res[i] = res[i]->next;
        }
        return res;
    }

    int count(ListNode *head) {
        int n = 0;
        while (head != nullptr) {
            ++n;
            head = head->next;
        }
        return n;
    }
};

#endif //CPP_725_H
