//
// Created by zhengxiaojian on 2020/12/1.
//

#ifndef CPP_63_H
#define CPP_63_H

#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        obstacleGrid[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        for (int i = 1; i < m; ++i)
            obstacleGrid[i][0] = obstacleGrid[i][0] == 1 ? 0 : obstacleGrid[i - 1][0];
        for (int j = 1; j < n; ++j)
            obstacleGrid[0][j] = obstacleGrid[0][j] == 1 ? 0 : obstacleGrid[0][j - 1];

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                obstacleGrid[i][j] =
                        obstacleGrid[i][j] == 1
                        ? 0
                        : obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
            }
        }

        return obstacleGrid[m - 1][n - 1];
    }
};

#endif //CPP_63_H
