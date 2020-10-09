//
// Created by zhengxiaojian on 2020/10/9.
//

#ifndef CPP_95_H
#define CPP_95_H

#include "../lib/TreeNode.h"

using namespace std;

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) return {};

        vector<vector<TreeNode *>> dp(n + 1, vector<TreeNode *>());
        dp[0] = {nullptr};
        dp[1] = {new TreeNode(1)};

        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                for (const auto &left : dp[j]) {
                    for (const auto &right : dp[i - j - 1]) {
                        auto t = new TreeNode(i, left, right);
                        order = 1;
                        dp[i].push_back(deepCopyTree(t));
                    }
                }
            }
        }

        dp[0] = {};

        return dp[n];
    }

    int order = 1;

    TreeNode *deepCopyTree(TreeNode *root) {
        if (root == nullptr) return root;

        auto *left = deepCopyTree(root->left);
        auto *node = new TreeNode(order++);
        node->left = left;
        auto *right = deepCopyTree(root->right);
        node->right = right;

        return node;
    }
};

#endif //CPP_95_H
