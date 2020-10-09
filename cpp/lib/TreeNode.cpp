//
// Created by zhengxiaojian on 2020/9/29.
//

#include <queue>
#include <iostream>
#include "TreeNode.h"

TreeNode *buildTree(const std::vector<int> &input) {
    if (input.empty()) return nullptr;

    std::queue<TreeNode *> queue;

    auto *root = new TreeNode(input[0]);
    queue.push(root);

    int i = 1;

    while (i < input.size() && !queue.empty()) {
        auto *node = queue.front();
        queue.pop();

        if (i < input.size() && input[i] != null) {
            node->left = new TreeNode(input[i]);
            queue.push(node->left);
        }
        ++i;

        if (i < input.size() && input[i] != null) {
            node->right = new TreeNode(input[i]);
            queue.push(node->right);
        }
        ++i;
    }

    return root;
}

auto preorder(const TreeNode *root) -> void {
    if (root == nullptr) return;

    std::cout << root->val << ",";

    preorder(root->left);

    preorder(root->right);

}

auto inorder(const TreeNode *root) -> void {
    if (root == nullptr) return;

    inorder(root->left);

    std::cout << root->val << ",";

    inorder(root->right);
}

auto postorder(const TreeNode *root) -> void {
    if (root == nullptr) return;

    postorder(root->left);

    postorder(root->right);

    std::cout << root->val << ",";
}
