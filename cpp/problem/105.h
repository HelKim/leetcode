//
// Created by zhengxiaojian on 2020/11/17.
//

#ifndef CPP_105_H
#define CPP_105_H

#include "../lib/TreeNode.h"
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<int, int> memo;
    int idx = 0;

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            memo.insert(pair(inorder[i], i));
        }
        return build(preorder, inorder, 0, preorder.size() - 1);
    }

    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int s, int e) {
        if (s > e) return nullptr;
        int val = preorder[idx++];
        auto *node = new TreeNode(val);
        if (s == e) return node;
        node->left = build(preorder, inorder, s, memo[val] - 1);
        node->right = build(preorder, inorder, memo[val] + 1, e);
        return node;
    }
};

#endif //CPP_105_H
