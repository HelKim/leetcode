//
// Created by zhengxiaojian on 2020/11/20.
//

#ifndef CPP_222_H
#define CPP_222_H

#include "../lib/TreeNode.h"

using namespace std;

class Solution {
public:
    int countNodes(TreeNode *root) {
        if (root == nullptr) return 0;
        int d = computeDepth(root);
        if (d == 0) return 1;

        int left = 1;
        int right = pow(2, d) - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (exist(mid, d, root)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return pow(2, d) - 1 + left;
    }

    bool exist(int idx, int d, TreeNode *root) {
        int left = 0;
        int right = pow(2, d) - 1;

        for (int i = 0; i < d; ++i) {
            int mid = left + (right - left) / 2;
            if (mid >= idx) {
                right = mid;
                root = root->left;
            } else {
                left = mid + 1;
                root = root->right;
            }
        }

        return root != nullptr;
    }

    int computeDepth(TreeNode *root) {
        int d = 0;
        while (root->left != nullptr) {
            ++d;
            root = root->left;
        }
        return d;
    }
};

#endif //CPP_222_H
