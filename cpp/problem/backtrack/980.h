//
// Created by zhengxiaojian on 2020/12/15.
//

#ifndef CPP_980_H
#define CPP_980_H

#include <vector>

using namespace std;

class Solution {
public:
    int sum = 0;
    int spaces = 0;
    vector<bool> visit;
    int step[4][2] = {{1,  0},
                      {-1, 0},
                      {0,  1},
                      {0,  -1}};

    int uniquePathsIII(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        visit.assign(n, vector(m, false));
        auto start = find_start(n, m, grid);

        dfs(start.first, start.second, n, m, 0, grid);
        return sum;
    }

    void dfs(int i, int j, int n, int m, int s, vector<vector<int>> &grid) {
        if (i < 0 || j < 0 || i >= n || j >= m || visit[i][j]) return;
        if (grid[i][j] == 2 && s == spaces) {
            ++sum;
            return;
        }
        if (grid[i][j] == -1 || grid[i][j] == 2) return;

        visit[i][j] = true;
        for (auto &x : step) {
            dfs(i + x[0], j + x[1], n, m, s + 1, grid);
        }
        visit[i][j] = false;
    }

    pair<int, int> find_start(int n, int m, vector<vector<int>> &grid) {
        pair<int, int> s;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0) ++spaces;
                else if (grid[i][j] == 1) s = {i, j};
            }
        }

        return s;
    }
};

#endif //CPP_980_H
