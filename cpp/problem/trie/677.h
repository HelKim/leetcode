//
// Created by zhengxiaojian on 2021/1/5.
//

#ifndef CPP_677_H
#define CPP_677_H

#include <string>
#include <vector>

using namespace std;

struct TrieNode {
    int val = 0;
    vector<TrieNode *> children = vector<TrieNode *>(26, nullptr);
};

class MapSum {
public:
    TrieNode *root = new TrieNode();

    /** Initialize your data structure here. */
    MapSum() {

    }

    void insert(string key, int val) {
        auto *cur = root;
        for (auto c : key) {
            int idx = c - 'a';
            if (!cur->children[idx])
                cur->children[idx] = new TrieNode();
            cur = cur->children[idx];
        }
        cur->val = val;
    }

    int sum(string prefix) {
        auto *cur = root;
        for (auto c : prefix) {
            int idx = c - 'a';
            if (!cur->children[idx]) return 0;
            cur = cur->children[idx];
        }
        return dfs(cur);
    }

    int dfs(TrieNode *cur) {
        if (cur == nullptr) return 0;

        int s = 0;
        for (auto *child : cur->children) {
            s += dfs(child);
        }

        return s + cur->val;
    }
};

#endif //CPP_677_H
