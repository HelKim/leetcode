//
// Created by zhengxiaojian on 2020/12/9.
//

#ifndef CPP_337_H
#define CPP_337_H

#include "../../lib/TreeNode.h"
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<TreeNode *, int> memo;

    int rob(TreeNode *root) {
        return dfs(root);
    }

    int dfs(TreeNode *root) {
        if (root == nullptr) return 0;

        if (memo.find(root) != memo.end()) return memo[root];

        int left = dfs(root->left);
        int right = dfs(root->right);

        int lleft = 0;
        if (root->left != nullptr) lleft = dfs(root->left->left) + dfs(root->left->right);
        int rright = 0;
        if (root->right != nullptr) rright = dfs(root->right->right) + dfs(root->right->left);

        int r = max(left + right, root->val + lleft + rright);
        memo[root] = r;
        return r;
    }
};

#endif //CPP_337_H
