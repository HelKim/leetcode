//
// Created by zhengxiaojian on 2020/10/9.
//

#ifndef CPP_102_H
#define CPP_102_H

#include <vector>
#include <queue>
#include "../../lib/TreeNode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> vec;

            for (int i = 0; i < size; ++i) {
                auto node = q.front();
                q.pop();
                vec.push_back(node->val);

                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }

            result.push_back(vec);
        }

        return result;
    }
};

#endif //CPP_102_H
