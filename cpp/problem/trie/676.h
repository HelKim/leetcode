//
// Created by zhengxiaojian on 2021/1/5.
//

#ifndef CPP_676_H
#define CPP_676_H

#include <vector>
#include <string>

using namespace std;

struct TrieNode {
    vector<TrieNode *> children = vector<TrieNode *>(26, nullptr);
    bool is_terminal = false;
};

class MagicDictionary {
public:
    TrieNode *root;

    /** Initialize your data structure here. */
    MagicDictionary() {
        root = new TrieNode();
    }

    void buildDict(vector <string> dictionary) {
        for (auto &word : dictionary) {
            auto *cur = root;
            for (auto c : word) {
                int idx = c - 'a';
                if (!cur->children[idx]) {
                    cur->children[idx] = new TrieNode();
                }
                cur = cur->children[idx];
            }
            cur->is_terminal = true;
        }
    }

    bool search(string searchWord) {
        return search(searchWord, true, root, 0);
    }

    bool search(string &word, bool change, TrieNode *cur, int s) {
        for (int i = s; i < word.size(); ++i) {
            int idx = word[i] - 'a';

            if (change) {
                for (int j = 0; j < 26; ++j) {
                    auto *child = cur->children[j];
                    if (child == nullptr || j == idx) continue;
                    if (search(word, false, child, i + 1)) return true;
                }
            }

            if (cur->children[idx] == nullptr) {
                return false;
            }
            cur = cur->children[idx];
        }

        return !change && cur->is_terminal;
    }
};

#endif //CPP_676_H
