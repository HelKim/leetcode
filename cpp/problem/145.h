//
// Created by zhengxiaojian on 2020/11/19.
//

#ifndef CPP_145_H
#define CPP_145_H

#include "../lib/TreeNode.h"
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> s;
        // 重点在于使用prev记录最后一个访问的节点，从而判断右子树是否已经访问过
        TreeNode *prev = nullptr;

        while (!s.empty() || root != nullptr) {
            while (root != nullptr) {
                s.push(root);
                root = root->left;
            }

            root = s.top();
            if (root->right == nullptr || prev == root->right) {
                result.push_back(root->val);
                prev = root;
                s.pop();
                root = nullptr;
            } else {
                root = root->right;
            }
        }

        return result;
    }
};

#endif //CPP_145_H
