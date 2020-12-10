//
// Created by zhengxiaojian on 2020/12/10.
//

#ifndef CPP_309_2_H
#define CPP_309_2_H

#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n < 2) return 0;

        vector<vector<int>> dp(n, vector(2, 0));

        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                dp[i][0] = 0;
                dp[i][1] = -prices[i];
                continue;
            }
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            if (i == 1) {
                dp[i][1] = max(-prices[i], -prices[i - 1]);
                continue;
            }
            dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
        }

        return dp[n - 1][0];
    }
};

#endif //CPP_309_2_H
