//
// Created by zhengxiaojian on 2020/12/20.
//

#ifndef CPP_417_H
#define CPP_417_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<pair<bool, bool>>> visit;

    int direction[4][2]{{0,  1},
                        {0,  -1},
                        {1,  0},
                        {-1, 0}};


    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix) {
        int n = matrix.size();
        if (n == 0) return {};
        int m = matrix[0].size();

        visit.assign(n, vector(m, pair(false, false)));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i == 0 || j == 0) && !visit[i][j].first) dfs(i, j, true, matrix);
                if ((i == n - 1 || j == m - 1) && !visit[i][j].second) dfs(i, j, false, matrix);
            }
        }

        vector<vector<int>> res;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (visit[i][j].first && visit[i][j].second) res.push_back(vector<int>{i, j});
            }
        }

        return res;
    }

    void dfs(int i, int j, bool first, vector<vector<int>> &matrix) {
        if (first) {
            visit[i][j].first = true;
        } else {
            visit[i][j].second = true;
        }
        for (auto &dir : direction) {
            int x = dir[0] + i;
            int y = dir[1] + j;
            if (x < 0 || x == matrix.size() || y < 0 || y == matrix[0].size()) continue;
            if (matrix[x][y] < matrix[i][j]) continue;
            if (first && !visit[x][y].first || !first && !visit[x][y].second)
                dfs(x, y, first, matrix);
        }

    }
};

#endif //CPP_417_H
