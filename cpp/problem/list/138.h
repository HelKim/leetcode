//
// Created by zhengxiaojian on 2020/12/28.
//

#ifndef CPP_138_H
#define CPP_138_H

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    Node *copyRandomList(Node *head) {
        if (head == nullptr) return nullptr;

        unordered_map<Node *, Node *> map;
        auto *dummy = new Node(0);
        auto *p = dummy;
        while (head != nullptr) {
            if (!map.count(head)) {
                map.insert({head, new Node(head->val)});
            }
            if (head->random) {
                if (!map.count(head->random)) {
                    map.insert({head->random, new Node(head->random->val)});
                }
                map[head]->random = map[head->random];
            }
            p->next = map[head];
            p = p->next;
            head = head->next;
        }

        return dummy->next;
    }
};

#endif //CPP_138_H
