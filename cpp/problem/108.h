//
// Created by zhengxiaojian on 2020/11/17.
//

#ifndef CPP_108_H
#define CPP_108_H

#include "../lib/TreeNode.h"
#include <vector>

using namespace std;

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return build(nums, 0, nums.size() - 1);
    }

    TreeNode *build(vector<int> &nums, int s, int e) {
        if (s > e) return nullptr;

        int mid = (s + e) / 2;
        auto *node = new TreeNode(nums[mid]);
        node->left = build(nums, s, mid - 1);
        node->right = build(nums, mid + 1, e);

        return node;
    }
};

#endif //CPP_108_H
