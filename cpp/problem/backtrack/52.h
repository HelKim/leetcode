//
// Created by zhengxiaojian on 2020/12/15.
//

#ifndef CPP_52_H
#define CPP_52_H

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> board;
    int sum = 0;

    int totalNQueens(int n) {
        board.assign(n, -1);
        backtrack(0, n);
        return sum;
    }

    void backtrack(int i, int n) {
        if (i == n) {
            ++sum;
            return;
        }

        for (int j = 0; j < n; ++j) {
            if (isValid(i, j)) {
                board[i] = j;
                backtrack(i + 1, n);
                board[i] = -1;
            }
        }
    }

    bool isValid(int i, int j) {
        for (int k = 0; k < board.size(); ++k) {
            if (board[k] == j) return false;
            int offset = abs(i - k);
            if (j - offset >= 0 && board[k] == j - offset) return false;
            if (j + offset < board.size() && board[k] == j + offset) return false;
        }
        return true;
    }
};

#endif //CPP_52_H
