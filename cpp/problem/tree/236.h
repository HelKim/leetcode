//
// Created by zhengxiaojian on 2020/11/20.
//

#ifndef CPP_236_H
#define CPP_236_H

#include "../../lib/TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr) return nullptr;

        if (root->val == p->val || root->val == q->val) return root;

        auto *left = lowestCommonAncestor(root->left, p, q);
        auto *right = lowestCommonAncestor(root->right, p, q);

        if (left && right) return root;
        return left == nullptr ? right : left;
    }
};

#endif //CPP_236_H
