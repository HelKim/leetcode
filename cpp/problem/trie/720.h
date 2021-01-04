//
// Created by zhengxiaojian on 2021/1/4.
//

#ifndef CPP_720_H
#define CPP_720_H

#include <string>
#include <vector>

using namespace std;

struct TrieNode {
    vector<TrieNode *> children = vector<TrieNode *>(26, nullptr);
    bool is_terminal = false;

    char ch;

    TrieNode() = default;

    explicit TrieNode(int c) {
        this->ch = c;
    }
};

class Solution {
public:
    TrieNode *root = new TrieNode();

    string longestWord(vector<string> &words) {
        build(words);
        dfs(root);

        return ans;
    }

    void build(vector<string> &words) {
        for (auto &w : words) {
            auto *cur = root;

            for (auto c : w) {
                if (cur->children[c - 'a'] == nullptr)
                    cur->children[c - 'a'] = new TrieNode(c);
                cur = cur->children[c - 'a'];
            }

            cur->is_terminal = true;
        }
    }

    int max_length = 0;
    string ans;
    string tmp;

    void dfs(TrieNode *r) {
        if (tmp.size() > max_length) {
            max_length = tmp.size();
            ans = tmp;
        }

        for (auto *c : r->children) {
            if (c == nullptr || !c->is_terminal) continue;
            tmp.push_back(c->ch);
            dfs(c);
            tmp.pop_back();
        }
    }
};

#endif //CPP_720_H
