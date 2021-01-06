//
// Created by zhengxiaojian on 2021/1/5.
//

#ifndef CPP_648_H
#define CPP_648_H

#include <vector>
#include <string>

using namespace std;

struct TrieNode {
    vector<TrieNode *> children = vector<TrieNode *>(26, nullptr);
    int flag = -1;
};

class Solution {
public:
    TrieNode *root = new TrieNode();

    string replaceWords(vector<string> &dictionary, string sentence) {
        const string delim = " ";
        vector<string> words = split(sentence, delim);
        build(dictionary);

        string res;
        for (auto &w : words) {
            int idx = find(w);
            if (idx != -1) w = dictionary[idx];
            res += w + " ";
        }
        res.pop_back();
        return res;
    }

    int find(string &word) {
        auto *cur = root;
        for (auto c : word) {
            int idx = c - 'a';
            if (cur->flag != -1) return cur->flag;
            if (cur->children[idx] == nullptr) return -1;
            cur = cur->children[idx];
        }
        return cur->flag;
    }

    void build(vector<string> &dict) {
        for (int i = 0; i < dict.size(); ++i) {
            auto *cur = root;

            for (auto c : dict[i]) {
                int idx = c - 'a';
                if (cur->children[idx] == nullptr)
                    cur->children[idx] = new TrieNode();
                cur = cur->children[idx];
            }

            cur->flag = i;
        }
    }

    vector<string> split(const string &s, const string &delimiter) {
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        string token;
        vector<string> res;

        while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
            token = s.substr(pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back(token);
        }

        res.push_back(s.substr(pos_start));
        return res;
    }
};

#endif //CPP_648_H
