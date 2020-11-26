//
// Created by zhengxiaojian on 2020/11/17.
//

#ifndef CPP_106_H
#define CPP_106_H

#include "../../lib/TreeNode.h"
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<int, int> memo;
    int idx;

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            memo.insert(pair(inorder[i], i));
        }
        idx = postorder.size() - 1;
        return build(inorder, postorder, 0, idx);
    }

    TreeNode *build(vector<int> &inorder, vector<int> &postorder, int s, int e) {
        if (s > e) return nullptr;
        int val = postorder[idx--];
        auto *node = new TreeNode(val);
        node->right = build(inorder, postorder, memo[val] + 1, e);
        node->left = build(inorder, postorder, s, memo[val] - 1);
        return node;
    }
};

#endif //CPP_106_H
