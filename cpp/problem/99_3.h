//
// Created by zhengxiaojian on 2020/11/3.
//

#ifndef CPP_99_3_H
#define CPP_99_3_H

#include "../lib/TreeNode.h"
// Morris算法
class Solution {
public:
    void recoverTree(TreeNode *root) {
        TreeNode *x = nullptr, *y = nullptr,
                *pred = nullptr, *predecessor = nullptr;
        while (root != nullptr) {
            if (root->left != nullptr) {
                predecessor = root->left;
                while (predecessor->right != nullptr && predecessor->right != root) {
                    predecessor = predecessor->right;
                }

                if (predecessor->right == nullptr) {
                    predecessor->right = root;
                    root = root->left;
                    continue;
                }

                if (pred != nullptr && pred->val > root->val) {
                    if (x == nullptr) {
                        x = pred;
                    }
                    y = root;
                }
                pred = root;
                root = root->right;
                predecessor->right = nullptr;
            } else {
                if (pred != nullptr && pred->val > root->val) {
                    if (x == nullptr) {
                        x = pred;
                    }
                    y = root;
                }
                pred = root;
                root = root->right;
            }
        }

        auto temp = x->val;
        x->val = y->val;
        y->val = temp;
    }
};

#endif //CPP_99_3_H
