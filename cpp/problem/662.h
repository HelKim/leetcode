//
// Created by zhengxiaojian on 2020/11/24.
//

#ifndef CPP_662_H
#define CPP_662_H

#include "../lib/TreeNode.h"

using namespace std;

class Solution {
public:
    vector<pair<unsigned long long, unsigned long >> v;
    unsigned long long mmax = 0;

    int widthOfBinaryTree(TreeNode *root) {
        dfs(root, 0, 0);
        return (int) mmax;
    }

    void dfs(TreeNode *root, unsigned long long idx, unsigned long long l) {
        if (root == nullptr) return;

        if (v.size() == l) {
            v.emplace_back(idx, idx);
        } else {
            v[l].second = idx;
        }
        mmax = max(v[l].second - v[l].first + 1, mmax);

        dfs(root->left, 2 * idx, l + 1);
        dfs(root->right, 2 * idx + 1, l + 1);
    }
};

#endif //CPP_662_H
