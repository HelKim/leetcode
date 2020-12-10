//
// Created by zhengxiaojian on 2020/12/10.
//

#ifndef CPP_714_2_H
#define CPP_714_2_H

#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices, int fee) {
        int n = prices.size();
        if (n < 2) return 0;

        vector<vector<int>> dp(n, vector(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};

#endif //CPP_714_2_H
