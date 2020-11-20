//
// Created by zhengxiaojian on 2020/11/20.
//

#ifndef CPP_226_H
#define CPP_226_H

#include "../lib/TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        if (root == nullptr) return nullptr;

        TreeNode *left = invertTree(root->right);
        TreeNode *right = invertTree(root->left);

        root->left = left;
        root->right = right;

        return root;
    }
};

#endif //CPP_226_H
