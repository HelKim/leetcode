//
// Created by zhengxiaojian on 2020/11/23.
//

#ifndef CPP_450_H
#define CPP_450_H

#include "../../lib/TreeNode.h"

class Solution {
public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        auto **p = &root;

        while (*p != nullptr) {
            if ((*p)->val > key) {
                p = &(*p)->left;
            } else if ((*p)->val < key) {
                p = &(*p)->right;
            } else break;
        }

        if (*p == nullptr) return root;

        if ((*p)->left == nullptr) {
            *p = (*p)->right;
            return root;
        }

        if ((*p)->right == nullptr) {
            *p = (*p)->left;
            return root;
        }

        auto *right = (*p)->right;
        *p = (*p)->left;

        auto *mostRight = *p;
        while (mostRight->right != nullptr) mostRight = mostRight->right;
        mostRight->right = right;

        return root;
    }
};

#endif //CPP_450_H
