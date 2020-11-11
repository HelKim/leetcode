//
// Created by zhengxiaojian on 2020/11/11.
//

#ifndef CPP_100_H
#define CPP_100_H

#include "../lib/TreeNode.h"

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        if (p == nullptr || q == nullptr) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        }

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
#endif //CPP_100_H
