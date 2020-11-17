//
// Created by zhengxiaojian on 2020/11/17.
//

#ifndef CPP_114_H
#define CPP_114_H

#include "../lib/TreeNode.h"

using namespace std;

class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        if (root->left == nullptr) {
            flatten(root->right);
            return;
        }

        auto mostRight = root->left;
        while (mostRight->right != nullptr) {
            mostRight = mostRight->right;
        }
        mostRight->right = root->right;

        root->right = root->left;
        root->left = nullptr;

        flatten(root->right);
    }
};
#endif //CPP_114_H
