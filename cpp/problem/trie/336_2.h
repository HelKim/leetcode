//
// Created by zhengxiaojian on 2021/1/4.
//

#ifndef CPP_336_2_H
#define CPP_336_2_H

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

    vector<vector<int>> palindromePairs(vector<string> &words) {
        build(words);

        vector<vector<int>> res;

        for (int i = 0; i < words.size(); ++i) {
            int m = words[i].size();
            for (int j = 0; j <= m; ++j) {
                if (j > 0 && isPalindrome(words[i], 0, j - 1)) {
                    int right_id = findWord(words[i], j, m - 1);
                    if (right_id != i && right_id != -1) {
                        res.push_back({right_id, i});
                    }
                }

                if (isPalindrome(words[i], j, m - 1)) {
                    int left_id = findWord(words[i], 0, j - 1);
                    if (left_id != -1 && left_id != i) {
                        res.push_back({i, left_id});
                    }
                }
            }
        }

        return res;
    }

    int findWord(const string &s, int left, int right) {
        auto *cur = root;
        while (left <= right) {
            if (cur->children[s[left] - 'a'] == nullptr) return -1;
            cur = cur->children[s[left] - 'a'];
            ++left;
        }
        return cur->flag;
    }

    void build(vector<string> &words) {
        for (int i = 0; i < words.size(); ++i) {
            auto &word = words[i];

            auto *cur = root;
            for (int j = word.size() - 1; j >= 0; --j) {
                if (cur->children[word[j] - 'a'] == nullptr)
                    cur->children[word[j] - 'a'] = new TrieNode();
                cur = cur->children[word[j] - 'a'];
            }
            cur->flag = i;
        }
    }

    bool isPalindrome(const string &s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
};

#endif //CPP_336_2_H
