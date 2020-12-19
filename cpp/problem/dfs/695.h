//
// Created by zhengxiaojian on 2020/12/19.
//

#ifndef CPP_695_H
#define CPP_695_H

#include <vector>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int ans = 0;
        int m = grid[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    ans = max(ans, dfs(i, j, grid));
                }
            }
        }

        return ans;
    }

    int dfs(int i, int j, vector<vector<int>> &grid) {
        if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size()) {
            return 0;
        }
        if (grid[i][j] == 0) return 0;
        grid[i][j] = 0;

        return 1 + dfs(i + 1, j, grid) + dfs(i - 1, j, grid)
               + dfs(i, j - 1, grid) + dfs(i, j + 1, grid);
    }
};

#endif //CPP_695_H
