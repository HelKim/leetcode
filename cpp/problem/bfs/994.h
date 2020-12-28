//
// Created by zhengxiaojian on 2020/12/28.
//

#ifndef CPP_994_H
#define CPP_994_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector <vector<int>> &grid) {
        queue <pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();

        int direction[4][2]{
                {0,  1},
                {0,  -1},
                {1,  0},
                {-1, 0}
        };

        int total = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    ++total;
                } else if (grid[i][j] == 0) ++total;
            }
        }

        if (total == n * m) return 0;

        int step = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz-- > 0) {
                auto p = q.front();
                q.pop();

                for (auto &dir : direction) {
                    int x = dir[0] + p.first;
                    int y = dir[1] + p.second;
                    if (x < 0 || x == n || y < 0 || y == m || grid[x][y] == 2 || grid[x][y] == 0) continue;
                    ++total;
                    grid[x][y] = 2;
                    q.push({x, y});
                }
            }
            ++step;
        }

        return total == n * m ? step - 1 : -1;
    }
};

#endif //CPP_994_H
