//
// Created by zhengxiaojian on 2020/10/9.
//
#include <vector>
#include <stack>
#include "../lib/TreeNode.h"

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

            auto *p = s.top();
            s.pop();
            result.push_back(p->val);

            if (p->right != nullptr) {
                root = p->right;
            }
        }

        return result;
    }
};