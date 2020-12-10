//
// Created by zhengxiaojian on 2020/12/9.
//

#ifndef CPP_188_3_H
#define CPP_188_3_H

#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        if (k == 0 || n < 2) return 0;
        if (k >= n / 2) k = n / 2;

        vector<vector<vector<int>>> dp(n, vector(k + 1, vector(2, 0)));
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= k; ++j) {
                if (i == 0) {
                    dp[i][j][0] = 0;
                    dp[i][j][1] = -prices[i];
                    continue;
                }

                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }

        return dp[n - 1][k][0];
    }
};

#endif //CPP_188_3_H
