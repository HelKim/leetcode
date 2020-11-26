//
// Created by zhengxiaojian on 2020/11/23.
//

#ifndef CPP_404_H
#define CPP_404_H

#include "../../lib/TreeNode.h"

using namespace std;

class Solution {
public:
    int sumOfLeftLeaves(TreeNode *root) {
        if (root == nullptr) return 0;

        int s = 0;

        if (root->left != nullptr
                && root->left->left == nullptr
                && root->left->right == nullptr) {
            s += root->left->val;
        }

        return s + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }

};

#endif //CPP_404_H
