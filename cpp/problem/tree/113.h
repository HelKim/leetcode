//
// Created by zhengxiaojian on 2020/11/17.
//

#ifndef CPP_113_H
#define CPP_113_H

#include "../../lib/TreeNode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        pathSum(root, sum, 0);
        return result;
    }

    void pathSum(TreeNode *root, int sum, int val) {
        if (root == nullptr) return;

        temp.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr && val + root->val == sum) {
            result.push_back(temp);
        }

        pathSum(root->left, sum, val + root->val);
        pathSum(root->right, sum, val + root->val);

        temp.pop_back();
    }
};

#endif //CPP_113_H
