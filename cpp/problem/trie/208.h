//
// Created by zhengxiaojian on 2021/1/3.
//

#ifndef CPP_208_H
#define CPP_208_H

#include <string>
#include <vector>

using namespace std;

struct TrieNode {
    char ch;
    bool is_terminal = false;
    vector<TrieNode *> children = vector<TrieNode *>(26, nullptr);

    TrieNode() = default;

    explicit TrieNode(char c) {
        this->ch = c;
    }
};

class Trie {
public:
    TrieNode *root = new TrieNode();

    /** Initialize your data structure here. */
    Trie() {

    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        if (word.empty()) return;

        auto *cur = root;

        for (auto c : word) {
            if (cur->children[c - 'a'] == nullptr)
                cur->children[c - 'a'] = new TrieNode(c);
            cur = cur->children[c - 'a'];
        }

        cur->is_terminal = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto *cur = root;

        for (auto c : word) {
            if (cur->children[c - 'a'] == nullptr) return false;
            cur = cur->children[c - 'a'];
        }

        return cur->is_terminal;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto *cur = root;

        for (auto c : prefix) {
            if (cur->children[c - 'a'] == nullptr) return false;
            cur = cur->children[c - 'a'];
        }

        return true;
    }
};

#endif //CPP_208_H
