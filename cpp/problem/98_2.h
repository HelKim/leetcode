//
// Created by zhengxiaojian on 2020/10/11.
//

#ifndef CPP_98_2_H
#define CPP_98_2_H

#include "../lib/TreeNode.h"

using namespace std;

class Solution {
public:
    bool helper(TreeNode *root, long long lower, long long upper) {
        if (root == nullptr) return true;

        if (root->val <= lower || root->val >= upper)
            return false;

        return helper(root->left, lower, root->val) &&
               helper(root->right, root->val, upper);
    }

    bool isValidBST(TreeNode *root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};

#endif //CPP_98_2_H
