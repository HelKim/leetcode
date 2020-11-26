//
// Created by zhengxiaojian on 2020/11/25.
//

#ifndef CPP_669_H
#define CPP_669_H

#include "../../lib/TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode *trimBST(TreeNode *root, int low, int high) {
        root = getProper(root, low, high);

        if (root == nullptr) return nullptr;

        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;
    }

    TreeNode *getProper(TreeNode *root, int low, int high) {
        while (root != nullptr && (root->val < low || root->val > high)) {
            if (root->val < low) root = root->right;
            else if (root->val > high) root = root->left;
        }
        return root;
    }
};

#endif //CPP_669_H
