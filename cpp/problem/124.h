//
// Created by zhengxiaojian on 2020/11/19.
//

#ifndef CPP_124_H
#define CPP_124_H

#include "../lib/TreeNode.h"
using namespace std;

class Solution {
public:
    int result = INT_MIN;

    int maxPathSum(TreeNode *root) {
        maxPathSum_(root);
        return result;
    }

    int maxPathSum_(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = maxPathSum_(root->left);
        int right = maxPathSum_(root->right);

        int r = max(root->val + max(left, right), root->val);
        result = max(result, max(r, root->val + left + right));
        return r;
    }
};
#endif //CPP_124_H
