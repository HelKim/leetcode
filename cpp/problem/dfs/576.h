//
// Created by zhengxiaojian on 2021/1/4.
//

#ifndef CPP_576_H
#define CPP_576_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<vector<unsigned long long >>> memo;
    const int MOD = 1000000007;

    int findPaths(int m, int n, int N, int i, int j) {
        memo.assign(m, vector(n, vector(N + 1, -1ULL)));
        auto ans = dfs(i, j, m, n, N);
        return ans;
    }

    unsigned long long dfs(int i, int j, int m, int n, int N) {
        if (i < 0 || j < 0 || i == m || j == n) {
            return 1;
        }
        if (N == 0) return 0;
        if (memo[i][j][N] != -1) return memo[i][j][N];

        auto s = dfs(i, j + 1, m, n, N - 1)
                 + dfs(i, j - 1, m, n, N - 1)
                 + dfs(i + 1, j, m, n, N - 1)
                 + dfs(i - 1, j, m, n, N - 1);
        s = s % MOD;

        memo[i][j][N] = s;

        return s;
    }
};

#endif //CPP_576_H
