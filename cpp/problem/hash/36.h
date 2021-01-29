//
// Created by zhengxiaojian on 2021/1/11.
//

#ifndef CPP_36_H
#define CPP_36_H

#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        vector<unordered_set<int>> row(9), col(9), matrix(9);

        for (int x = 0; x < 9; ++x) {
            for (int y = 0; y < 9; ++y) {
                if (board[x][y] == '.') continue;
                if (row[x].count(board[x][y])
                    || col[y].count(board[x][y])
                    || matrix[get_matrix_idx(x, y)].count(board[x][y]))
                    return false;
                row[x].insert(board[x][y]);
                col[y].insert(board[x][y]);
                matrix[get_matrix_idx(x, y)].insert(board[x][y]);
            }
        }

        return true;
    }

    int get_matrix_idx(int x, int y) {
        return (x / 3) * 3 + y / 3;
    }
};

#endif //CPP_36_H
