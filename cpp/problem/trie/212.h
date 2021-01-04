//
// Created by zhengxiaojian on 2021/1/4.
//

#ifndef CPP_212_H
#define CPP_212_H

#include <vector>
#include <string>

using namespace std;

struct TrieNode {
    vector<TrieNode *> children = vector<TrieNode *>(26, nullptr);
};

class Solution {
public:
    TrieNode *root = new TrieNode();
    vector<vector<bool>> visit;

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        int n = board.size();
        int m = board[0].size();
        visit.assign(n, vector(m, false));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dfs(i, j, root, board, 0);
            }
        }

        vector<string> res;
        for (auto &word : words) {
            if (find(word)) res.push_back(word);
        }

        return res;
    }

    bool find(const string &str) {
        auto *cur = root;
        for (auto c : str) {
            if (cur->children[c - 'a'] == nullptr) return false;
            cur = cur->children[c - 'a'];
        }
        return true;
    }

    void dfs(int i, int j, TrieNode *r, vector<vector<char>> &board, int level) {
        int n = board.size();
        int m = board[0].size();
        if (i < 0 || i == n || j < 0 || j == m || visit[i][j] || level > 10) return;
        visit[i][j] = true;

        if (r->children[board[i][j] - 'a'] == nullptr)
            r->children[board[i][j] - 'a'] = new TrieNode();

        r = r->children[board[i][j] - 'a'];

        dfs(i, j - 1, r, board, level + 1);
        dfs(i, j + 1, r, board, level + 1);
        dfs(i - 1, j, r, board, level + 1);
        dfs(i + 1, j, r, board, level + 1);

        visit[i][j] = false;
    }
};

#endif //CPP_212_H
