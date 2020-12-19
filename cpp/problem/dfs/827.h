//
// Created by zhengxiaojian on 2020/12/19.
//

#ifndef CPP_827_H
#define CPP_827_H

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int direction[4][2]{{0,  1},
                        {0,  -1},
                        {1,  0},
                        {-1, 0}};

    int largestIsland(vector<vector<int>> &grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        int ans = 0;

        int idx = 2;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    int cnt = dfs(i, j, idx++, grid);
                    nums.push_back(cnt);
                    ans = max(ans, cnt);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0) ans = max(ans, get_sum(i, j, grid, nums));
            }
        }

        return ans;
    }

    int get_sum(int i, int j, vector<vector<int>> &grid, vector<int> &nums) {
        unordered_set<int> set;
        for (int idx = 0; idx < 4; ++idx) {
            int n = get_num(i + direction[idx][0], j + direction[idx][1], grid);
            if (n != -1) set.insert(n);
        }

        int s = 1;
        for (auto num : set) {
            if (num >= 2)
                s += nums[num - 2];
        }
        return s;
    }

    int get_num(int i, int j, vector<vector<int>> &grid) {
        if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size()) return -1;
        return grid[i][j];
    }

    int dfs(int i, int j, int idx, vector<vector<int>> &grid) {
        if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size()) return 0;
        if (grid[i][j] != 1) return 0;
        grid[i][j] = idx;

        return 1 + dfs(i, j - 1, idx, grid) +
               dfs(i, j + 1, idx, grid) +
               dfs(i - 1, j, idx, grid) +
               dfs(i + 1, j, idx, grid);
    }
};

#endif //CPP_827_H
