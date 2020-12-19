//
// Created by zhengxiaojian on 2020/12/19.
//

#ifndef CPP_463_H
#define CPP_463_H

#include <vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>> &grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();

        int ans = 0;
        int direction[4][2]{{0,  1},
                            {1,  0},
                            {-1, 0},
                            {0,  -1}};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    for (auto ix : direction) {
                        int x = i + ix[0];
                        int y = j + ix[1];
                        if (x < 0 || x == n || y < 0 || y == m || grid[x][y] == 0) {
                            ++ans;
                        }
                    }
                }
            }
        }

        return ans;
    }
};

#endif //CPP_463_H
