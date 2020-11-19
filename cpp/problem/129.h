//
// Created by zhengxiaojian on 2020/11/19.
//

#ifndef CPP_129_H
#define CPP_129_H

#include "../lib/TreeNode.h"

class Solution {
public:
    int sum = 0;

    int sumNumbers(TreeNode* root) {
        sumNumbers(root, 0);
        return sum;
    }

    void sumNumbers(TreeNode* root, int s) {
        if (root == nullptr) return;
        s = s * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            sum += s;
        }
        sumNumbers(root->left, s);
        sumNumbers(root->right, s);
    }
};
#endif //CPP_129_H
