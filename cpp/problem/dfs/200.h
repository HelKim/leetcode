//
// Created by zhengxiaojian on 2020/12/19.
//

#ifndef CPP_200_H
#define CPP_200_H

#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();

        int s = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    ++s;
                    dfs(i, j, grid);
                }
            }
        }

        return s;
    }

    void dfs(int i, int j, vector<vector<char>> &grid) {
        if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size()) return;
        if (grid[i][j] == '0') return;
        grid[i][j] = '0';

        dfs(i + 1, j, grid);
        dfs(i - 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i, j - 1, grid);
    }
};

#endif //CPP_200_H
