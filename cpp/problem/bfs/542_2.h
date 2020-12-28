//
// Created by zhengxiaojian on 2020/12/27.
//

#ifndef CPP_542_2_H
#define CPP_542_2_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int direction[4][2] = {
            {0,  1},
            {0,  -1},
            {1,  0},
            {-1, 0}
    };

    vector <vector<int>> updateMatrix(vector <vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector <vector<bool>> visit(n, vector(m, false));

        queue <pair<int, int>> q;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    q.push({i, j});
                    visit[i][j] = true;
                }
            }
        }

        int level = 0;

        while (!q.empty()) {
            ++level;
            int sz = q.size();
            while (sz-- > 0) {
                auto p = q.front();
                q.pop();
                for (auto &dir : direction) {
                    int x = p.first + dir[0];
                    int y = p.second + dir[1];
                    if (x < 0 || x == n || y < 0 || y == m || visit[x][y]) continue;
                    visit[x][y] = true;
                    matrix[x][y] = level;
                    q.push({x, y});
                }
            }
        }

        return matrix;
    }
};

#endif //CPP_542_2_H
