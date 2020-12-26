//
// Created by zhengxiaojian on 2020/12/26.
//

#ifndef CPP_993_H
#define CPP_993_H

#include "../../lib/TreeNode.h"
#include <queue>

using namespace std;

class Solution {
public:
    bool isCousins(TreeNode *root, int x, int y) {
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();

            TreeNode *xp = nullptr;
            TreeNode *yp = nullptr;

            while (sz-- > 0) {
                auto *p = q.front();
                q.pop();

                if (p->left != nullptr) {
                    q.push(p->left);
                    if (p->left->val == x) xp = p;
                    if (p->left->val == y) yp = p;
                }

                if (p->right != nullptr) {
                    q.push(p->right);
                    if (p->right->val == x) xp = p;
                    if (p->right->val == y) yp = p;
                }
            }

            if (xp != nullptr && yp != nullptr)
                return xp != yp;

            if (xp != nullptr || yp != nullptr)
                return false;
        }

        return false;
    }
};

#endif //CPP_993_H
