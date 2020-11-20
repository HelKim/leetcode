//
// Created by zhengxiaojian on 2020/11/20.
//

#ifndef CPP_199_2_H
#define CPP_199_2_H

#include "../lib/TreeNode.h"

using namespace std;

// DFS
class Solution {
public:
    vector<int> result;

    vector<int> rightSideView(TreeNode *root) {
        dfs(root, 0);
        return result;
    }

    void dfs(TreeNode *root, int level) {
        if (root == nullptr) return;

        if (result.size() <= level) {
            result.push_back(root->val);
        }
        dfs(root->right, level + 1);
        dfs(root->left, level + 1);
    }
};

#endif //CPP_199_2_H
