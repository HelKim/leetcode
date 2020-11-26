//
// Created by zhengxiaojian on 2020/10/9.
//
#include <vector>
#include <stack>
#include "../../lib/TreeNode.h"

using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;

        stack<TreeNode *> s;
        while (root != nullptr || !s.empty()) {
            while (root != nullptr) {
                s.push(root);
                root = root->left;
            }

            root = s.top();
            s.pop();
            result.push_back(root->val);
            root = root->right;
        }
        return result;
    }
};