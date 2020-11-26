//
// Created by zhengxiaojian on 2020/11/25.
//

#ifndef CPP_671_H
#define CPP_671_H

#include "../../lib/TreeNode.h"

using namespace std;

class Solution {
public:
    int r = -1;

    int findSecondMinimumValue(TreeNode *root) {
        dfs(root);
        return r;
    }

    void dfs(TreeNode *root) {
        if (root == nullptr) return;

        if (root->left != nullptr && root->left->val != root->right->val) {
            int m = max(root->left->val, root->right->val);
            r = r == -1 ? m : min(r, m);
            if (m == root->left->val) dfs(root->right);
            else dfs(root->left);
        } else {
            dfs(root->left);
            dfs(root->right);
        }
    }
};

#endif //CPP_671_H
