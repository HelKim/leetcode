//
// Created by zhengxiaojian on 2020/11/24.
//

#ifndef CPP_572_H
#define CPP_572_H

#include "../../lib/TreeNode.h"

using namespace std;

class Solution {
public:
    bool isSubtree(TreeNode *s, TreeNode *t) {
        if (s == nullptr && t == nullptr) return true;
        if (s == nullptr || t == nullptr) return false;

        if (s->val == t->val && isSameTree(s, t))
            return true;

        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }

    bool isSameTree(TreeNode *s, TreeNode *t) {
        if (s == nullptr && t == nullptr) return true;
        if (s == nullptr || t == nullptr) return false;

        return s->val == t->val && isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
    }
};

#endif //CPP_572_H
