//
// Created by zhengxiaojian on 2020/12/28.
//

#ifndef CPP_1162_H
#define CPP_1162_H

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

    int maxDistance(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] = 2;
                }
            }
        }

        if (q.size() == 0 || q.size() == n * m) return -1;

        int level = -1;
        while (!q.empty()) {
            ++level;
            int sz = q.size();
            while (sz-- > 0) {
                auto p = q.front();
                q.pop();
                for (auto &dir : direction) {
                    int x = p.first + dir[0];
                    int y = p.second + dir[1];
                    if (x < 0 || x == n || y < 0 || y == m || grid[x][y] == 2) continue;
                    grid[x][y] = 2;
                    q.push({x, y});
                }
            }
        }
        return level;
    }
};

#endif //CPP_1162_H
