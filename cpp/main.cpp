
#include <iostream>
#include "problem/449.h"

int main() {
    Codec codec;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(2);

    string s = codec.serialize(buildTree({2, 1}));
    auto *p = codec.deserialize(s);

    return 0;
}
