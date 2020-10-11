//
// Created by zhengxiaojian on 2020/10/10.
//

#ifndef CPP_95_2_H
#define CPP_95_2_H

#include "../lib/TreeNode.h"

using namespace std;

class Solution {

public:
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) return {};

        return generateTrees(1, n);
    }

    vector<TreeNode *> generateTrees(int start, int end) {
        if (start > end) return {nullptr};

        vector<TreeNode *> allTrees;

        for (int i = start; i <= end; ++i) {
            auto left_tree = generateTrees(start, i - 1);
            auto right_tree = generateTrees(i + 1, end);

            for (const auto &l : left_tree) {
                for (const auto &r : right_tree) {
                    auto *root = new TreeNode(i, l, r);
                    allTrees.emplace_back(root);
                }
            }
        }

        return allTrees;
    }
};

#endif //CPP_95_2_H
