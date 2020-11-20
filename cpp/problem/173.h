//
// Created by zhengxiaojian on 2020/11/20.
//

#ifndef CPP_173_H
#define CPP_173_H

#include "../lib/TreeNode.h"
#include <stack>

using namespace std;

class BSTIterator {
public:
    stack<TreeNode *> s;

    BSTIterator(TreeNode *root) {
        helper(root);
    }

    void helper(TreeNode *root) {
        while (root != nullptr) {
            s.push(root);
            root = root->left;
        }
    }

    /** @return the next smallest number */
    int next() {
        auto *root = s.top();
        s.pop();
        helper(root->right);
        return root->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
};

#endif //CPP_173_H
