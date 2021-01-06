//
// Created by zhengxiaojian on 2021/1/5.
//

#ifndef CPP_472_2_H
#define CPP_472_2_H

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

struct TrieNode {
    vector<TrieNode *> children = vector<TrieNode *>(26, nullptr);
    int idx = -1;
};

class Solution {
public:
    TrieNode *root = new TrieNode();
    vector<string> res;
    unordered_set<string_view> memo;

    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        build(words);
        for (auto &w : words) {
            dfs(0, w, root, false, words);
        }
        return res;
    }

    bool dfs(int s, string &str, TrieNode *cur, bool second, vector<string> &words) {
        if (cur == nullptr) return false;

        if (memo.count(string_view(str).substr(s)) && second) {
            res.push_back(str);
            return true;
        }

        for (int i = s; i < str.size(); ++i) {
            int ch = str[i] - 'a';
            if (cur->idx > -1 && dfs(i, str, root, true, words)) {
                memo.insert(string_view(str).substr(i));
                return true;
            }
            if (cur->children[ch] == nullptr) return false;
            cur = cur->children[ch];
        }

        if (second && cur->idx > -1) {
            res.push_back(str);
            return true;
        }
        return false;
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

#endif //CPP_472_2_H
