//
// Created by zhengxiaojian on 2020/11/23.
//

#ifndef CPP_513_H
#define CPP_513_H

#include "../../lib/TreeNode.h"

class Solution {
public:
    int maxLevel = 0;
    int left = 0;
    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 1);
        return left;
    }

    void dfs(TreeNode *root, int level) {
        if (root == nullptr) return;

        dfs(root->left, level + 1);

        if (level > maxLevel) {
            maxLevel = level;
            left = root->val;
        }

        dfs(root->right, level + 1);
    }
};
#endif //CPP_513_H
