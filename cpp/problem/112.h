//
// Created by zhengxiaojian on 2020/11/17.
//

#ifndef CPP_112_H
#define CPP_112_H

#include "../lib/TreeNode.h"

using namespace std;

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        return calPathSum(root, sum, 0);
    }

    bool calPathSum(TreeNode *root, int sum, int val) {
        if (root == nullptr) return false;

        if (root->left == nullptr && root->right == nullptr && root->val + val == sum) return true;

        return calPathSum(root->left, sum, val + root->val) || calPathSum(root->right, sum, val + root->val);
    }
};

#endif //CPP_112_H
