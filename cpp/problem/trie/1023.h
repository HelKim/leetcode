//
// Created by zhengxiaojian on 2021/1/5.
//

#ifndef CPP_1023_H
#define CPP_1023_H

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode *> children;
    int idx = -1;
};

class Solution {
public:
    TrieNode *root = new TrieNode();
    vector<bool> res;

    vector<bool> camelMatch(vector <string> &queries, string pattern) {
        build(queries);
        res.assign(queries.size(), false);
        dfs(root, 0, pattern);
        return res;
    }

    void dfs(TrieNode *cur, int s, string &pattern) {
        if (cur == nullptr) return;

        if (s == pattern.size() && cur->idx > -1) {
            res[cur->idx] = true;
        }

        for (auto &child : cur->children) {
            if (s < pattern.size() && child.first == pattern[s]) {
                dfs(child.second, s + 1, pattern);
            } else {
                if (child.first >= 'a' && child.first <= 'z') {
                    dfs(child.second, s, pattern);
                }
            }
        }
    }

    void build(vector <string> &queries) {
        for (int i = 0; i < queries.size(); ++i) {
            auto *cur = root;

            for (auto c : queries[i]) {
                if (!cur->children.count(c)) {
                    cur->children.insert({c, new TrieNode()});
                }
                cur = cur->children[c];
            }

            cur->idx = i;
        }
    }
};

#endif //CPP_1023_H
