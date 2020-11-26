//
// Created by zhengxiaojian on 2020/11/17.
//

#ifndef CPP_107_H
#define CPP_107_H

#include <queue>
#include <list>
#include "../../lib/TreeNode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        if (root == nullptr) return vector<vector<int>>();

        queue<TreeNode *> q;
        q.push(root);
        list<vector<int>> result;
        while (!q.empty()) {
            int size = q.size();
            vector<int> r;
            for (int i = 0; i < size; ++i) {
                auto *t = q.front();
                q.pop();
                r.push_back(t->val);
                if (t->left != nullptr) q.push(t->left);
                if (t->right != nullptr) q.push(t->right);
            }
            result.push_front(r);
        }

        return vector<vector<int>>(result.begin(), result.end());
    }
};

#endif //CPP_107_H
