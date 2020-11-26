//
// Created by zhengxiaojian on 2020/11/24.
//

#ifndef CPP_637_H
#define CPP_637_H

#include "../../lib/TreeNode.h"
#include <queue>

using namespace std;

class Solution {
public:
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> r;
        if (root == nullptr) return r;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            long long s = 0;

            for (int i = 0; i < size; ++i) {
                auto *p = q.front();
                q.pop();

                s += p->val;
                if (p->left) q.push(p->left);
                if (p->right) q.push(p->right);
            }

            r.push_back((double) s / size);
        }

        return r;
    }
};

#endif //CPP_637_H
