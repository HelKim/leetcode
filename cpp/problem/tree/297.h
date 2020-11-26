//
// Created by zhengxiaojian on 2020/11/23.
//

#ifndef CPP_297_H
#define CPP_297_H

#include "../../lib/TreeNode.h"
#include <string>
#include <queue>

using namespace std;

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (root == nullptr) {
            return "[]";
        }

        vector<string> v;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; ++i) {
                auto *t = q.front();
                q.pop();

                if (t == nullptr) {
                    v.emplace_back("null");
                } else {
                    v.emplace_back(to_string(t->val));
                    q.push(t->left);
                    q.push(t->right);
                }
            }
        }

        string s = "[" + v[0];

        for (int i = 1; i < v.size(); ++i) {
            s += "," + v[i];
        }

        return s + "]";
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        string s = data.substr(1, data.size() - 2);
        auto v = split(s, ",");

        if (v.empty()) return nullptr;

        queue<TreeNode *> q;
        auto *root = new TreeNode(stoi(v[0]));
        q.push(root);

        int i = 1;

        while (!q.empty() && i < v.size()) {
            auto *node = q.front();
            q.pop();

            if (v[i] != "null") {
                node->left = new TreeNode(stoi(v[i]));
                q.push(node->left);
            }
            ++i;
            if (i < v.size() && v[i] != "null") {
                node->right = new TreeNode(stoi(v[i]));
                q.push(node->right);
            }
            ++i;
        }

        return root;
    }

    vector<string> split(const string &str, const string &delim) {
        if (str.length() == 0) return {};

        vector<string> v;

        int start = 0;
        int end = str.find(delim);
        while (end != string::npos) {
            v.push_back(str.substr(start, end - start));
            start = end + delim.length();
            end = str.find(delim, start);
        }
        v.push_back(str.substr(start, end));
        return v;
    }
};

#endif //CPP_297_H
