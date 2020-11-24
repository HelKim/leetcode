//
// Created by zhengxiaojian on 2020/11/24.
//

#ifndef CPP_538_H
#define CPP_538_H

#include "../lib/TreeNode.h"

using namespace std;

class Solution {
public:
    int s = 0;

    TreeNode* convertBST(TreeNode* root) {
        convert(root);
        return root;
    }

    void convert(TreeNode *root) {
        if (root == nullptr) {
            return;
        }

        convert(root->right);

        s += root->val;
        root->val = s;

        convert(root->left);
    }
};
#endif //CPP_538_H
