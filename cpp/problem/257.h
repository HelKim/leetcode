//
// Created by zhengxiaojian on 2020/11/20.
//

#ifndef CPP_257_H
#define CPP_257_H

#include "../lib/TreeNode.h"
#include <numeric>
#include <string>

using namespace std;


class Solution {
public:
    vector<string> result;
    vector<int> t;

    vector<string> binaryTreePaths(TreeNode *root) {
        binaryTree(root);
        return result;
    }

    void binaryTree(TreeNode *root) {
        if (root == nullptr) return;

        t.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            result.push_back(join(t));
        }

        binaryTree(root->left);
        binaryTree(root->right);

        t.pop_back();
    }

    string join(const vector<int> & v) {
        if (v.empty()) return "";
        if (v.size() == 1) return to_string(v[0]);

        string s = to_string(v[0]);

        for (int i = 1; i < v.size(); ++i) {
            s += "->" + to_string(v[i]);
        }

        return s;
    }
};

#endif //CPP_257_H
