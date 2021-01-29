//
// Created by zhengxiaojian on 2021/1/29.
//

#ifndef CPP_1631_2_H
#define CPP_1631_2_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>> &heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> visit(m, vector(n, false));

        auto cmp = [](const auto &e1, const auto &e2) {
            auto &&[x1, y1, d1] = e1;
            auto &&[x2, y2, d2] = e2;
            return d1 > d2;
        };

        vector<vector<int>> direction{{0,  1},
                                      {0,  -1},
                                      {1,  0},
                                      {-1, 0}};

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cmp)> q(cmp);

        q.push({0, 0, 0});

        vector<vector<int>> dist(m, vector(n, INT_MAX / 2));
        dist[0][0] = 0;

        while (!q.empty()) {
            auto[x, y, d] = q.top();
            q.pop();
            if (visit[x][y]) continue;
            if (x == m - 1 && y == n - 1) break;
            visit[x][y] = true;

            for (auto &dir : direction) {
                int nx = dir[0] + x;
                int ny = dir[1] + y;
                if (nx == m || nx < 0 || ny == n || ny < 0 || visit[nx][ny]) continue;
                int _dist = max(dist[x][y], abs(heights[x][y] - heights[nx][ny]));
                if (dist[nx][ny] > _dist) {
                    dist[nx][ny] = _dist;
                    q.push({nx, ny, _dist});
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};

#endif //CPP_1631_2_H
