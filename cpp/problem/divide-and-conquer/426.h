//
// Created by zhengxiaojian on 2021/1/1.
//

#ifndef CPP_426_H
#define CPP_426_H

class Node {
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node *treeToDoublyList(Node *root) {
        if (root == nullptr) return root;
        return (change(root)).first;
    }

    pair<Node *, Node *> change(Node *root) {
        auto *new_head = root;
        if (root->left != nullptr) {
            auto l = change(root->left);
            new_head = l.first;
            l.second->right = root;
            root->left = l.second;
        }
        auto *new_tail = root;
        if (root->right != nullptr) {
            auto r = change(root->right);
            new_tail = r.second;
            root->right = r.first;
            r.first->left = root;
        }
        new_head->left = new_tail;
        new_tail->right = new_head;

        return {new_head, new_tail};
    }
};

#endif //CPP_426_H
