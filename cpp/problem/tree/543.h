//
// Created by zhengxiaojian on 2020/11/24.
//

#ifndef CPP_543_H
#define CPP_543_H

#include "../../lib/TreeNode.h"

using namespace std;

class Solution {
public:
    int m = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return m;
    }

    int dfs(TreeNode *root) {
        if (root == nullptr) return 0;

        int l = dfs(root->left);
        int r = dfs(root->right);

        m = max(m, l + r);

        return max(l, r) + 1;
    }
};
#endif //CPP_543_H
