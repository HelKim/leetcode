//
// Created by zhengxiaojian on 2021/1/3.
//

#ifndef CPP_211_H
#define CPP_211_H

#include <vector>
#include <string>

using namespace std;

struct TrieNode {
    char ch;
    bool is_terminal = false;
    vector<TrieNode *> children = vector<TrieNode *>(26, nullptr);

    TrieNode() = default;

    explicit TrieNode(char ch) {
        this->ch = ch;
    }
};

class WordDictionary {
public:
    TrieNode *root = new TrieNode();

    /** Initialize your data structure here. */
    WordDictionary() {

    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto *cur = root;

        for (auto c : word) {
            if (cur->children[c - 'a'] == nullptr) {
                cur->children[c - 'a'] = new TrieNode(c);
            }
            cur = cur->children[c - 'a'];
        }

        cur->is_terminal = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(root, word, 0);
    }

    bool search(TrieNode *r, string &word, int s) {
        for (int i = s; i < word.size(); ++i) {
            if (word[i] == '.') {
                for (auto child : r->children) {
                    if (child == nullptr) continue;
                    if (search(child, word, i + 1)) return true;
                }
                return false;
            }
            if (r->children[word[i] - 'a'] == nullptr) return false;
            r = r->children[word[i] - 'a'];
        }

        return r->is_terminal;
    }
};
#endif //CPP_211_H
