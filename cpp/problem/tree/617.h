//
// Created by zhengxiaojian on 2020/11/24.
//

#ifndef CPP_617_H
#define CPP_617_H

#include "../../lib/TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) return nullptr;
        if (t1 == nullptr) return t2;
        if (t2 == nullptr) return t1;

        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);

        return t1;
    }
};
#endif //CPP_617_H
