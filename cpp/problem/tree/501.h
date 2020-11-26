//
// Created by zhengxiaojian on 2020/11/23.
//

#ifndef CPP_501_H
#define CPP_501_H

#include "../../lib/TreeNode.h"

using namespace std;

class Solution {
public:
    vector<int> r;
    long long pre = LONG_MIN;
    int preCount = 0;
    int maxCount = 0;

    vector<int> findMode(TreeNode *root) {
        inorder(root);
        return r;
    }

    void inorder(TreeNode *root) {
        if (root == nullptr) return;

        inorder(root->left);
        if (pre == root->val) {
            ++preCount;
            if (preCount > maxCount) {
                maxCount = preCount;
                r = {root->val};
            } else if (preCount == maxCount) {
                r.push_back(root->val);
            }
        } else {
            pre = root->val;
            preCount = 1;

            if (preCount > maxCount) {
                maxCount = preCount;
                r = {root->val};
            } else if (preCount == maxCount) {
                r.push_back(root->val);
            }
        }
        inorder(root->right);
    }
};

#endif //CPP_501_H
