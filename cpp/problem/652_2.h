//
// Created by zhengxiaojian on 2020/11/24.
//

#ifndef CPP_652_2_H
#define CPP_652_2_H

#include "../lib/TreeNode.h"
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    unordered_map<string, int> s;
    vector<TreeNode *> r;

    string collect(TreeNode *root) {
        if (root == nullptr) return "#";

        string str = to_string(root->val) + ',' + collect(root->left) + ',' + collect(root->right);

        if (s.find(str) == s.end()) {
            s.insert({str, 1});
        } else {
            s[str]++;
        }

        if (s[str] == 2) {
            r.push_back(root);
        }

        return str;
    }

    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        collect(root);
        return r;
    }
};

#endif //CPP_652_2_H
