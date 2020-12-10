//
// Created by zhengxiaojian on 2020/12/9.
//

#ifndef CPP_188_H
#define CPP_188_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<vector<int>>> memo;

    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        if (k == 0 || n < 2) return 0;
        if (k > n / 2) k = n / 2;

        vector<vector<int>> dp(n, vector(n, 0));
        vector<vector<int>> mins;
        calc_min(prices, mins);

        memo.assign(n, vector(n, vector(k + 1, -1)));

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                dp[i][j] = max(dp[i][j - 1], prices[j] - mins[i][j - 1]);
            }
        }

        return calc(0, n - 1, k, dp);
    }

    int calc(int i, int j, int k, vector<vector<int>> &dp) {
        if (i >= j) return 0;
        if (k == 1) return dp[i][j];

        if (memo[i][j][k] != -1) return memo[i][j][k];
        int ans = dp[i][j];
        for (int x = i; x <= j; ++x) {
            ans = max(ans, dp[i][x] + calc(x + 1, j, k - 1, dp));
        }

        memo[i][j][k] = ans;
        return ans;
    }

    void calc_min(vector<int> &prices, vector<vector<int>> &result) {
        int n = prices.size();
        result.assign(n, vector<int>(n, 0));

        for (int i = 0; i < n; ++i) {
            result[i][i] = prices[i];
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                result[i][j] = min(result[i][j - 1], prices[j]);
            }
        }
    }
};

#endif //CPP_188_H
