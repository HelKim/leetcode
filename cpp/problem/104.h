//
// Created by zhengxiaojian on 2020/11/17.
//

#ifndef CPP_104_H
#define CPP_104_H

#include "../lib/TreeNode.h"

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == nullptr) return 0;
        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

#endif //CPP_104_H
