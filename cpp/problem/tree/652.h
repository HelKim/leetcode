//
// Created by zhengxiaojian on 2020/11/24.
//

#ifndef CPP_652_H
#define CPP_652_H

#include "../../lib/TreeNode.h"
#include <set>

using namespace std;

class Solution {
public:
    vector<TreeNode *> allTrees;
    vector<TreeNode *> result;

    void addTrees(TreeNode *root) {
        if (root == nullptr) return;
        for (auto *p : result) {
            if (p == root || isSameTree(root, p)) return;
        }
        addTrees(root->left);
        addTrees(root->right);
        result.push_back(root);
    }

    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;

        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    void find(TreeNode *root) {
        if (root == nullptr) return;

        for (auto *p : allTrees) {
            if (p != root && p->val == root->val && isSameTree(root, p)) {
                addTrees(root);
                return;
            }
        }

        find(root->left);
        find(root->right);

        allTrees.push_back(root);
    }

    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        find(root);
        return result;
    }
};

#endif //CPP_652_H
