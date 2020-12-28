//
// Created by zhengxiaojian on 2020/12/26.
//

#ifndef CPP_529_H
#define CPP_529_H

#include <vector>

using namespace std;

class Solution {
public:
    int direction[8][2]{
            {-1, -1},
            {-1, 0},
            {-1, 1},
            {0,  -1},
            {0,  1},
            {1,  -1},
            {1,  0},
            {1,  1}
    };

    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click) {
        int x = click[0], y = click[1];
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        }
        calc(board, x, y);
        return board;
    }

    void calc(vector<vector<char>> &board, int x, int y) {
        int s = 0;
        board[x][y] = 'B';
        for (auto &dir : direction) {
            int x_next = x + dir[0];
            int y_next = y + dir[1];

            if (x_next < 0 || x_next == board.size() || y_next < 0 || y_next == board[0].size()) continue;
            if (board[x_next][y_next] == 'M') ++s;
        }

        if (s > 0) board[x][y] = s + '0';
        else {
            for (auto &dir : direction) {
                int x_next = x + dir[0];
                int y_next = y + dir[1];

                if (x_next < 0 || x_next == board.size() || y_next < 0 || y_next == board[0].size()) continue;
                if (board[x_next][y_next] == 'E') calc(board, x_next, y_next);
            }
        }
    }
};

#endif //CPP_529_H
