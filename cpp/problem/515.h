//
// Created by zhengxiaojian on 2020/11/24.
//

#ifndef CPP_515_H
#define CPP_515_H

#include "../lib/TreeNode.h"

using namespace std;

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> r;
        dfs(root, 0, r);
        return r;
    }

    void dfs(TreeNode *root, int level, vector<int> &v) {
        if (root == nullptr) return;

        if (v.size() == level) {
            v.push_back(root->val);
        } else {
            v[level] = max(v[level], root->val);
        }

        dfs(root->left, level + 1, v);
        dfs(root->right, level + 1, v);
    }
};
#endif //CPP_515_H
