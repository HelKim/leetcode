//
// Created by zhengxiaojian on 2020/11/24.
//

#ifndef CPP_530_H
#define CPP_530_H

#include "../lib/TreeNode.h"

using namespace std;

class Solution {
public:
    int m = INT_MAX;
    int pre;
    bool first = true;

    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return m;
    }

    void dfs(TreeNode *root) {
        if (root == nullptr) return;

        dfs(root->left);

        if (first) first = false;
        else {
            m = min(root->val - pre, m);
        }

        pre = root->val;

        dfs(root->right);
    }
};
#endif //CPP_530_H
