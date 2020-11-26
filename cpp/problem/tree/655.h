//
// Created by zhengxiaojian on 2020/11/24.
//

#ifndef CPP_655_H
#define CPP_655_H

#include "../../lib/TreeNode.h"
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    int m = 0;
    vector<vector<string>> r;

    int getHeight(TreeNode *root) {
        if (root == nullptr) return 0;
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }

    void print(TreeNode *root, int s, int e, int h) {
        if (root == nullptr) return;
        int mid = s + (e - s) / 2;
        r[h][mid] = to_string(root->val);
        print(root->left, s, mid - 1, h + 1);
        print(root->right, mid + 1, e, h + 1);
    }

    vector<vector<string>> printTree(TreeNode *root) {
        m = getHeight(root);
        if (m == 0) return r;

        int n = pow(2, m) - 1;

        r.assign(m, vector<string>(n, ""));

        print(root, 0, n - 1, 0);
        return r;
    }
};

#endif //CPP_655_H
