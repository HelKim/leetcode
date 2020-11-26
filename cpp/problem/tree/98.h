//
// Created by zhengxiaojian on 2020/10/10.
//

#ifndef CPP_98_H
#define CPP_98_H

#include "../../lib/TreeNode.h"

using namespace std;

class Solution {
public:
    int pivot = INT_MIN;
    bool result = true;
    bool first = true;

    bool isValidBST(TreeNode *root) {
        dfs(root);
        return result;
    }

    void dfs(TreeNode *root) {
        if (root == nullptr) return;

        dfs(root->left);

        if (first) {
            first = false;
        } else if (root->val <= pivot) {
            result = false;
        }
        pivot = root->val;

        dfs(root->right);
    }
};

#endif //CPP_98_H
