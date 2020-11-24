//
// Created by zhengxiaojian on 2020/11/24.
//

#ifndef CPP_563_H
#define CPP_563_H

#include "../lib/TreeNode.h"

using namespace std;

class Solution {
public:
    int s = 0;

    int findTilt(TreeNode* root) {
        dfs(root);

        return s;
    }

    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;

        int l = dfs(root->left);
        int r = dfs(root->right);

        s += abs(l - r);

        return l + r + root->val;
    }
};
#endif //CPP_563_H
