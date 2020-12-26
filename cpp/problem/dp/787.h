//
// Created by zhengxiaojian on 2020/12/25.
//

#ifndef CPP_787_H
#define CPP_787_H

#include <vector>

using namespace std;

class Solution {
public:
    const int INF = 0x3f3f3f3f;

    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K) {
        vector<vector<vector<int>>> dp(n, vector(n, vector(K + 1, INF)));
        vector<vector<int>> edges(n);

        for (const auto &flight : flights) {
            dp[flight[0]][flight[1]][0] = flight[2];
            edges[flight[1]].push_back(flight[0]);
        }

        for (int k = 1; k <= K; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dp[i][j][k] = dp[i][j][k - 1];
                    for (auto x : edges[j]) {
                        dp[i][j][k] = min(dp[i][j][k], dp[i][x][k - 1] + dp[x][j][0]);
                    }
                }
            }
        }

        return dp[src][dst][K] == INF ? -1 : dp[src][dst][K];
    }
};

#endif //CPP_787_H
