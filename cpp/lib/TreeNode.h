//
// Created by zhengxiaojian on 2020/9/29.
//

#ifndef LEETCODE_TREENODE_H
#define LEETCODE_TREENODE_H

#include <climits>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(-1), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *buildTree(const std::vector<int> &);

auto preorder(const TreeNode *root) -> void;

auto postorder(const TreeNode *root) -> void;

auto inorder(const TreeNode *root) -> void;

const int null = INT_MIN;

#endif //LEETCODE_TREENODE_H
