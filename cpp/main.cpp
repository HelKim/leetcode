
#include <iostream>
#include "problem/297.h"

int main() {
    Codec codec;

    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);

    string s = codec.serialize(root);
    auto *p = codec.deserialize(s);

    return 0;
}
