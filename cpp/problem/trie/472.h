//
// Created by zhengxiaojian on 2021/1/5.
//

#ifndef CPP_472_H
#define CPP_472_H

#include <vector>
#include <string>

using namespace std;

struct TrieNode {
    vector<TrieNode *> children = vector<TrieNode *>(26, nullptr);
    int idx = -1;
};

class Solution {
public:
    TrieNode *root = new TrieNode();
    vector<string> res;

    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        build(words);
        for (auto &w : words) {
            dfs(0, w, root, words);
        }
        return res;
    }

    bool dfs(int s, string &str, TrieNode *cur, vector<string> &words) {
        if (cur == nullptr) return false;

        if (s == str.size() && cur->idx > -1 && words[cur->idx] != str) {
            res.push_back(str);
            return true;
        }

        if (s == str.size()) return false;

        if (cur->idx > -1 && dfs(s, str, root, words)) return true;

        return dfs(s + 1, str, cur->children[str[s] - 'a'], words);
    }

    void build(vector<string> &words) {
        for (int i = 0; i < words.size(); ++i) {
            auto *cur = root;
            for (auto c : words[i]) {
                int idx = c - 'a';
                if (!cur->children[idx])
                    cur->children[idx] = new TrieNode();
                cur = cur->children[idx];
            }
            cur->idx = i;
        }
        root->idx = -1;
    }
};

#endif //CPP_472_H
