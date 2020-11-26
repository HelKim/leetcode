//
// Created by zhengxiaojian on 2020/11/11.
//

#ifndef CPP_101_2_H
#define CPP_101_2_H

#include "../../lib/TreeNode.h"
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) return true;

        queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);

        while (!q.empty()) {
            int size = q.size();
            if ((size & 1) == 1) return false;

            vector<long long > v;
            for (int i = 0; i < size; ++i) {
                auto *t = q.front();
                q.pop();
                v.push_back(t == nullptr ? LONG_MIN : t->val);
                if (t != nullptr) {
                    q.push(t->left);
                    q.push(t->right);
                }
            }
            for (int i = 0; i < v.size() / 2; ++i) {
                if (v[i] != v[v.size() - i - 1]) return false;
            }
        }

        return true;
    }
};

#endif //CPP_101_2_H
