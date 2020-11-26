//
// Created by zhengxiaojian on 2020/11/24.
//

#ifndef CPP_623_H
#define CPP_623_H

#include "../../lib/TreeNode.h"

class Solution {
public:
    TreeNode *addOneRow(TreeNode *root, int v, int d) {
        if (d == 1) {
            auto *p = new TreeNode(v);
            p->left = root;
            return p;
        }
        addOneRow(root, v, d, 1);
        return root;
    }

    void addOneRow(TreeNode *root, int v, int d, int l) {
        if (root == nullptr) return;

        if (d - l == 1) {
            auto *p1 = new TreeNode(v);
            p1->left = root->left;
            auto *p2 = new TreeNode(v);
            p2->right = root->right;
            root->left = p1;
            root->right = p2;
        }

        addOneRow(root->left, v, d, l + 1);
        addOneRow(root->right, v, d, l + 1);
    }
};

#endif //CPP_623_H
