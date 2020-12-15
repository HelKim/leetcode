//
// Created by zhengxiaojian on 2020/12/15.
//

#ifndef CPP_51_H
#define CPP_51_H

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<char>> board;
    vector<vector<string>> result;

    vector<vector<string>> solveNQueens(int n) {
        board.assign(n, vector(n, '.'));
        backtrack(0, n);
        return result;
    }

    void backtrack(int i, int n) {
        if (i == n) {
            add_result();
            return;
        }

        for (int j = 0; j < n; ++j) {
            if (isValid(i, j)) {
                board[i][j] = 'Q';
                backtrack(i + 1, n);
                board[i][j] = '.';
            }
        }
    }

    void add_result() {
        vector<string> r;
        for (auto &line : board) {
            r.emplace_back(line.begin(), line.end());
        }
        result.push_back(r);
    }

    bool isValid(int i, int j) {
        for (int k = 0; k < board.size(); ++k) {
            if (board[k][j] == 'Q') return false;
            int offset = abs(i - k);
            if (j - offset >= 0 && board[k][j - offset] == 'Q') return false;
            if (j + offset < board.size() && board[j + offset] == 'Q') return false;
        }
        return true;
    }
};

#endif //CPP_51_H
