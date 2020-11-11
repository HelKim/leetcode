//
// Created by zhengxiaojian on 2020/11/11.
//

#ifndef CPP_101_H
#define CPP_101_H

#include "../lib/TreeNode.h"

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) return true;

        return isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;

        return p->val == q->val && isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
    }
};

#endif //CPP_101_H
