//
// Created by zhengxiaojian on 2020/11/19.
//

#ifndef CPP_144_H
#define CPP_144_H

#include "../lib/TreeNode.h"
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> s;

        while (!s.empty() || root != nullptr) {
            while (root != nullptr) {
                result.push_back(root->val);
                s.push(root);
                root = root->left;
            }
            root = s.top()->right;
            s.pop();
        }

        return result;
    }
};

#endif //CPP_144_H
