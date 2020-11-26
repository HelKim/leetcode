//
// Created by zhengxiaojian on 2020/11/24.
//

#ifndef CPP_606_H
#define CPP_606_H

#include "../../lib/TreeNode.h"
#include <string>

using namespace std;

class Solution {
public:
    string tree2str(TreeNode *t) {
        if (t == nullptr) return "";

        string l = tree2str(t->left);
        string r = tree2str(t->right);

        if (l.empty() && r.empty()) return to_string(t->val);

        string s = to_string(t->val);
        s += '(' + l + ')';
        if (!r.empty()) s += '(' + r + ')';

        return s;
    }
};

#endif //CPP_606_H
