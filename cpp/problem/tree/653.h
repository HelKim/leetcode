//
// Created by zhengxiaojian on 2020/11/24.
//

#ifndef CPP_653_H
#define CPP_653_H

#include "../../lib/TreeNode.h"

using namespace std;

class Solution {
public:
    vector<int> r;

    void inorder(TreeNode *root) {
        if (root == nullptr) return;
        inorder(root->left);
        r.push_back(root->val);
        inorder(root->right);
    }

    bool findTarget(TreeNode *root, int k) {
        inorder(root);
        int i = 0, j = r.size() - 1;
        while (i < j) {
            int s = r[i] + r[j];
            if (s == k) return true;
            if (s > k) --j;
            else ++i;
        }
        return false;
    }
};

#endif //CPP_653_H
