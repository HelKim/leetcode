//
// Created by zhengxiaojian on 2020/10/9.
//

#ifndef CPP_103_H
#define CPP_103_H

#include <vector>
#include "../lib/TreeNode.h"
#include <queue>
#include <list>

using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> result;

        if (root == nullptr) return result;

        queue<TreeNode *> q;
        q.push(root);
        bool reverse = false;

        while (!q.empty()) {
            int size = q.size();
            list<int> l;

            for (int i = 0; i < size; ++i) {
                auto *t = q.front();
                q.pop();
                if (reverse) {
                    l.push_front(t->val);
                } else {
                    l.push_back(t->val);
                }

                if (t->left != nullptr) q.push(t->left);
                if (t->right != nullptr) q.push(t->right);
            }

            result.emplace_back(l.begin(), l.end());

            reverse = !reverse;
        }

        return result;
    }
};

#endif //CPP_103_H
