//
// Created by zhengxiaojian on 2020/11/24.
//

#ifndef CPP_513_2_H
#define CPP_513_2_H

#include "../../lib/TreeNode.h"
#include <queue>

using namespace std;

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        int left = 0;

        while (!q.empty()) {
            int size = q.size();
            left = q.front()->val;

            for (int i = 0; i < size; ++i) {
                auto *p = q.front();
                q.pop();

                if (p->left) q.push(p->left);
                if (p->right) q.push(p->right);
            }
        }

        return left;
    }
};
#endif //CPP_513_2_H
