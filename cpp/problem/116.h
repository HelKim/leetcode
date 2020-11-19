//
// Created by zhengxiaojian on 2020/11/18.
//

#ifndef CPP_116_H
#define CPP_116_H
struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
};

class Solution {
public:
    Node *connect(Node *root) {
        if (root == nullptr) return root;

        connect(root->left, root->right);

        return root;
    }

    void connect(Node *p, Node *q) {
        if (p == nullptr || q == nullptr) return;

        p->next = q;

        connect(p->left, p->right);
        connect(p->right, q->left);
        connect(q->left, q->right);
    }
};

#endif //CPP_116_H
