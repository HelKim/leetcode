//
// Created by zhengxiaojian on 2020/11/23.
//

#ifndef CPP_449_H
#define CPP_449_H

#include "../../lib/TreeNode.h"

#include <string>

using namespace std;

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string r;
        preorder(root, r);
        return r.length() > 0 ? r.substr(1, r.length() - 1) : "";
    }

    void preorder(TreeNode *root, string &str) {
        if (root == nullptr) return;

        str += "," + to_string(root->val);

        preorder(root->left, str);

        preorder(root->right, str);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data.length() == 0) return nullptr;

        auto v = split(data, ",");

        return buildTree(0, v.size() - 1, v);
    }

    TreeNode *buildTree(int start, int end, const vector<int> &v) {
        if (end < start) return nullptr;

        auto *root = new TreeNode(v[start]);
        int bound = getBound(start, end, v);
        root->left = buildTree(start + 1, bound, v);
        root->right = buildTree(bound + 1, end, v);

        return root;
    }

    int getBound(int s, int e, const vector<int> &v) {
        int val = v[s];
        int i = s + 1;
        while (i <= e) {
            if (v[i] > val) {
                return i - 1;
            }
            ++i;
        }
        return i - 1;
    }

    vector<int> split(const string &str, const string &delim) {
        vector<int> v;

        if (str.length() == 0) return v;

        int start = 0;
        int end = str.find(delim);
        while (end != string::npos) {
            v.push_back(stoi(str.substr(start, end - start)));
            start = end + delim.length();
            end = str.find(delim, start);
        }
        v.push_back(stoi(str.substr(start, end)));
        return v;
    }
};

#endif //CPP_449_H
