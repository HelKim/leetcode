//
// Created by zhengxiaojian on 2020/12/26.
//

#ifndef CPP_993_H
#define CPP_993_H

#include "../../lib/TreeNode.h"
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<int, int> levels;
    unordered_map<int, TreeNode *> parents;

    bool isCousins(TreeNode *root, int x, int y) {
        dfs(root, nullptr, 0);

        return levels[x] == levels[y] && parents[x] != parents[y];
    }

    void dfs(TreeNode *root, TreeNode *p, int level) {
        if (root == nullptr) return;

        levels[root->val] = level;
        parents[root->val] = p;

        dfs(root->left, root, level + 1);
        dfs(root->right, root, level + 1);
    }
};

#endif //CPP_993_H
