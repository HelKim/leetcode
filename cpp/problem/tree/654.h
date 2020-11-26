//
// Created by zhengxiaojian on 2020/11/24.
//

#ifndef CPP_654_H
#define CPP_654_H

#include "../../lib/TreeNode.h"
#include <algorithm>

using namespace std;

class Solution {
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return buildTree(0, nums.size() - 1, nums);
    }

    TreeNode *buildTree(int s, int e, const vector<int> &nums) {
        if (s > e) return nullptr;

        int index = s, max = nums[s];
        for (int i = s + 1; i <= e; ++i) {
            if (nums[i] > max) {
                max = nums[i];
                index = i;
            }
        }

        auto *root = new TreeNode(nums[index]);
        root->left = buildTree(s, index - 1, nums);
        root->right = buildTree(index + 1, e, nums);

        return root;
    }
};

#endif //CPP_654_H
