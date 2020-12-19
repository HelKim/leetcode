//
// Created by zhengxiaojian on 2020/12/18.
//

#ifndef CPP_130_H
#define CPP_130_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> direction{{0,  1},
                                  {1,  0},
                                  {-1, 0},
                                  {0,  -1}};

    void solve(vector<vector<char>> &board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();

        for (int i = 0; i < n; ++i) {
            if (i == 0 || i == n - 1) {
                for (int j = 0; j < m; ++j) {
                    if (board[i][j] == 'O') dfs(i, j, board);
                }
            } else {
                if (board[i][0] == 'O') dfs(i, 0, board);
                if (board[i][m - 1] == 'O') dfs(i, m - 1, board);
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'V') board[i][j] = 'O';
            }
        }
    }

    void dfs(int i, int j, vector<vector<char>> &board) {
        if (i < 0 || i == board.size() || j < 0 || j == board[0].size()) return;
        if (board[i][j] == 'X' || board[i][j] == 'V') return;
        board[i][j] = 'V';

        for (auto &dir : direction) {
            int x = i + dir[0];
            int y = j + dir[1];
            dfs(x, y, board);
        }
    }
};

#endif //CPP_130_H
