//
// Created by zhengxiaojian on 2021/1/29.
//

#ifndef CPP_1631_H
#define CPP_1631_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<bool>> visit;
    int m, n;
    vector<vector<int>> direction = {{0,  1},
                                     {0,  -1},
                                     {1,  0},
                                     {-1, 0}};

    int minimumEffortPath(vector<vector<int>> &heights) {
        m = heights.size();
        n = heights[0].size();

        int left = 0, right = 1e+6 - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            visit.assign(m, vector(n, false));
            if (canReach(0, 0, heights, mid)) {
                right = mid - 1;
            } else left = mid + 1;
        }

        return left;
    }

    bool canReach(int x, int y, vector<vector<int>> &heights, int maxD) {
        if (x == m - 1 && y == n - 1) return true;
        visit[x][y] = true;

        for (auto &dir : direction) {
            int nx = dir[0] + x;
            int ny = dir[1] + y;
            if (nx == m || nx < 0 || ny == n || ny < 0 || visit[nx][ny]) continue;
            if (abs(heights[x][y] - heights[nx][ny]) > maxD) continue;
            if (canReach(nx, ny, heights, maxD)) return true;
        }

        return false;
    }

};

#endif //CPP_1631_H
