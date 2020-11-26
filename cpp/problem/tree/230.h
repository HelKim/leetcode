//
// Created by zhengxiaojian on 2020/11/20.
//

#ifndef CPP_230_H
#define CPP_230_H

#include "../../lib/TreeNode.h"

class Solution {
public:
    int l = 0;
    int result = 0;
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return result;
    }

    void dfs(TreeNode *root, int k) {
        if (root == nullptr) return;

        dfs(root->left, k);

        if (++l == k) {
            result = root->val;
            return;
        }

        dfs(root->right, k);
    }
};
#endif //CPP_230_H
