//
// Created by zhengxiaojian on 2020/11/20.
//

#ifndef CPP_199_H
#define CPP_199_H

#include "../../lib/TreeNode.h"
#include <queue>

using namespace std;
// BFS
class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> result;
        if (root == nullptr) return result;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            int last = 0;
            for (int i = 0; i < size; ++i) {
                auto *n = q.front();
                q.pop();
                last = n->val;
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            result.push_back(last);
        }

        return result;
    }
};

#endif //CPP_199_H
