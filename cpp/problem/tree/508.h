//
// Created by zhengxiaojian on 2020/11/23.
//

#ifndef CPP_508_H
#define CPP_508_H

#include "../../lib/TreeNode.h"
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<int, int> map;

    vector<int> findFrequentTreeSum(TreeNode *root) {
        dfs(root);

        vector<int> r;

        int maxCount = 0;

        for (const auto &v : map) {
            if (v.second > maxCount) {
                maxCount = v.second;
                r = {v.first};
            } else if (v.second == maxCount) {
                r.push_back(v.first);
            }
        }

        return r;
    }

    int dfs(TreeNode *root) {
        if (root == nullptr) return 0;

        int v = dfs(root->left) + dfs(root->right) + root->val;
        if (map.find(v) == map.end()) {
            map.insert({v, 1});
        } else {
            map[v]++;
        }
        return v;
    }
};

#endif //CPP_508_H
