//
// Created by zhengxiaojian on 2020/11/17.
//

#ifndef CPP_111_H
#define CPP_111_H

#include "../lib/TreeNode.h"

using namespace std;

class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == nullptr) return 0;

        if (root->left == nullptr) return minDepth(root->right) + 1;
        if (root->right == nullptr) return minDepth(root->left) + 1;

        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

#endif //CPP_111_H
