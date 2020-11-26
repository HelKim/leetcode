//
// Created by zhengxiaojian on 2020/11/17.
//

#ifndef CPP_110_H
#define CPP_110_H

#include "../../lib/TreeNode.h"

using namespace std;

class Solution {
public:
    bool bal = true;
    bool isBalanced(TreeNode *root) {
        treeHeight(root);
        return bal;
    }

    int treeHeight(TreeNode *root) {
        if (root == nullptr) return 0;

        int left = treeHeight(root->left);
        int right = treeHeight(root->right);

        if (abs(left - right) > 1) bal = false;

        return max(left, right) + 1;
    }
};

#endif //CPP_110_H
