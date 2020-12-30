//
// Created by zhengxiaojian on 2020/12/28.
//

#ifndef CPP_LISTNODE_H
#define CPP_LISTNODE_H

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#endif //CPP_LISTNODE_H
