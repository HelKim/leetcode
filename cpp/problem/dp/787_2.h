//
// Created by zhengxiaojian on 2020/12/26.
//

#ifndef CPP_787_2_H
#define CPP_787_2_H

#include <vector>

using namespace std;

class Solution {
public:
    const int INF = 0x3f3f3f3f;

    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K) {
        vector<vector<int>> dp(n, vector(K + 1, INF));
        vector<vector<pair<int, int>>> edges(n);

        for (const auto &flight : flights) {
            if (flight[0] == src) {
                dp[flight[1]][0] = flight[2];
            }
            edges[flight[1]].emplace_back(flight[0], flight[2]);
        }

        for (int k = 1; k <= K; ++k) {
            for (int i = 0; i < n; ++i) {
                dp[i][k] = dp[i][k - 1];
                for (auto x : edges[i]) {
                    dp[i][k] = min(dp[i][k], dp[x.first][k - 1] + x.second);
                }
            }
        }

        return dp[dst][K] == INF ? -1 : dp[dst][K];
    }
};

#endif //CPP_787_2_H
