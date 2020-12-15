//
// Created by zhengxiaojian on 2020/12/15.
//

#ifndef CPP_37_H
#define CPP_37_H

#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>> &board) {
        backtrack(0, 0, board);
    }

    bool backtrack(int i, int j, vector<vector<char>> &board) {
        if (i >= 9) return true;
        if (j >= 9) {
            return backtrack(i + 1, 0, board);
        }
        if (board[i][j] != '.') return backtrack(i, j + 1, board);

        for (int k = 1; k <= 9; ++k) {
            if (isValid(i, j, k + '0', board)) {
                board[i][j] = k + '0';
                if (backtrack(i, j + 1, board)) return true;
                board[i][j] = '.';
            }
        }

        return false;
    }

    bool isValid(int i, int j, char n, vector<vector<char>> &board) {
        for (int k = 0; k < 9; ++k) {
            if (board[i][k] == n) return false;
            if (board[k][j] == n) return false;
        }

        int x = (i / 3) * 3;
        int y = (j / 3) * 3;
        for (int a = 0; a < 3; ++a) {
            for (int b = 0; b < 3; ++b) {
                if (board[x + a][y + b] == n) {
                    return false;
                }
            }
        }

        return true;
    }
};

#endif //CPP_37_H
