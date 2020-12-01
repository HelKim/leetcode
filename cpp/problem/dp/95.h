//
// Created by zhengxiaojian on 2020/12/1.
//

#ifndef CPP_95_H
#define CPP_95_H

#include "../../lib/TreeNode.h"
#include <vector>

using namespace std;

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) return {};
        return generate(1, n);
    }

    vector<TreeNode *> generate(int s, int e) {
        if (s > e) return {nullptr};
        if (s == e) return {new TreeNode(s)};

        vector<TreeNode *> result;

        for (int i = s; i <= e; ++i) {
            auto left = generate(s, i - 1);
            auto right = generate(i + 1, e);
            for (auto *l : left) {
                for (auto *r : right) {
                    auto *node = new TreeNode(i);
                    node->left = l;
                    node->right = r;
                    result.push_back(node);
                }
            }
        }

        return result;
    }
};

#endif //CPP_95_H
