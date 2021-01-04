//
// Created by zhengxiaojian on 2021/1/4.
//

#ifndef CPP_212_2_H
#define CPP_212_2_H

#include <vector>
#include <string>

using namespace std;

struct TrieNode {
    bool is_terminal = false;
    vector<TrieNode *> children = vector<TrieNode *>(26, nullptr);
};

class Solution {
public:
    TrieNode *root = new TrieNode();
    vector<vector<bool>> visit;
    string tmp;
    vector<string> res;

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        int n = board.size();
        int m = board[0].size();

        visit.assign(n, vector(m, false));

        build(words);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                backtrack(i, j, root, board);
            }
        }

        return res;
    }

    void backtrack(int i, int j, TrieNode *cur, vector<vector<char>> &board) {
        if (cur->is_terminal) {
            res.push_back(tmp);
            cur->is_terminal = false;
        }

        int n = board.size();
        int m = board[0].size();
        if (i < 0 || i == n || j < 0 || j == m || visit[i][j]) return;

        if (cur->children[board[i][j] - 'a'] == nullptr) return;

        cur = cur->children[board[i][j] - 'a'];

        visit[i][j] = true;
        tmp.push_back(board[i][j]);
        backtrack(i, j + 1, cur, board);
        backtrack(i, j - 1, cur, board);
        backtrack(i - 1, j, cur, board);
        backtrack(i + 1, j, cur, board);
        tmp.pop_back();
        visit[i][j] = false;
    }

    void build(vector<string> &words) {
        for (auto &s : words) {
            auto *cur = root;
            for (auto c : s) {
                if (cur->children[c - 'a'] == nullptr)
                    cur->children[c - 'a'] = new TrieNode();
                cur = cur->children[c - 'a'];
            }
            cur->is_terminal = true;
        }
    }
};

#endif //CPP_212_2_H
