//
// Created by zhengxiaojian on 2020/11/18.
//

#ifndef CPP_117_H
#define CPP_117_H
struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
};

class Solution {
public:
    Node *connect(Node *root) {
        if (root == nullptr) return nullptr;

        Node *start = root;

        while (start != nullptr) {
            Node *nextStart = nullptr;
            Node *last = nullptr;

            for (Node *p = start; p != nullptr; p = p->next) {
                if (p->left != nullptr) {
                    handle(last, p->left, nextStart);
                }
                if (p->right != nullptr) {
                    handle(last, p->right, nextStart);
                }
            }

            start = nextStart;
        }

        return root;
    }

    static void handle(Node *&last, Node *&p, Node *&nextStart) {
        if (last) {
            last->next = p;
        }
        if (!nextStart) {
            nextStart = p;
        }
        last = p;
    }
};

#endif //CPP_117_H
