//
// Created by zhengxiaojian on 2020/11/2.
//

#ifndef CPP_99_H
#define CPP_99_H

#include "../../lib/TreeNode.h"

class Solution {
public:
    TreeNode *x = nullptr, *y = nullptr;
    TreeNode *last = nullptr;

    void recoverTree(TreeNode *root) {
        if (root == nullptr) return;

        inorder(root);
        auto temp = x->val;
        x->val = y->val;
        y->val = temp;
    }

    void inorder(TreeNode *root) {
        if (root == nullptr) return;

        inorder(root->left);
        if (last != nullptr && last->val > root->val) {
            if (x == nullptr) {
                x = last;
                y = root;
            } else {
                y = root;
            }
        }

        last = root;

        inorder(root->right);
    }
};

#endif //CPP_99_H
