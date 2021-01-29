//
// Created by zhengxiaojian on 2021/1/12.
//

#ifndef CPP_236_H
#define CPP_236_H

#include "../lib/TreeNode.h"

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr || root == p || root == q) return root;

        auto *left = lowestCommonAncestor(root->left, p, q);
        auto *right = lowestCommonAncestor(root->right, p, q);

        return left && right ? root : left ? left : right;
    }
};

#endif //CPP_236_H
