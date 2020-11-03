//
// Created by zhengxiaojian on 2020/11/2.
//

#ifndef CPP_99_2_H
#define CPP_99_2_H

#include "../lib/TreeNode.h"
#include <stack>

class Solution {
public:
    TreeNode *x = nullptr, *y = nullptr;
    TreeNode *last = nullptr;

    void recoverTree(TreeNode *root) {
        if (root == nullptr) return;

        std::stack<TreeNode *> s;

        while (!s.empty() || root != nullptr) {
            while (root != nullptr) {
                s.push(root);
                root = root->left;
            }

            root = s.top();
            s.pop();

            if (last != nullptr && last->val > root->val) {
                if (x == nullptr) {
                    x = last;
                }
                y = root;
            }
            last = root;

            root = root->right;
        }

        auto temp = x->val;
        x->val = y->val;
        y->val = temp;
    }
};

#endif //CPP_99_2_H
