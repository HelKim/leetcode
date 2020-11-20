//
// Created by zhengxiaojian on 2020/11/20.
//

#ifndef CPP_230_2_H
#define CPP_230_2_H

#include "../lib/TreeNode.h"

#include <stack>

using namespace std;

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> s;
        s.push(root);

        while (!s.empty() || root != nullptr) {
            while (root != nullptr) {
                s.push(root);
                root = root->left;
            }

            root = s.top();
            s.pop();
            if (--k == 0) return root->val;

            root = root->right;
        }

        return 0;
    }
};
#endif //CPP_230_2_H
