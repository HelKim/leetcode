//
// Created by zhengxiaojian on 2020/12/3.
//

#ifndef CPP_518_3_H
#define CPP_518_3_H

#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int> &coins) {
        if (amount == 0) return 1;

        int n = coins.size();
        if (n == 0) return 0;

        vector<vector<int>> dp(n, vector(amount + 1, 0));
        for (int i = 0; i < n; ++i) dp[i][0] = 1;
        for (int i = 1; i * coins[0] <= amount; ++i) {
            dp[0][coins[0] * i] = 1;
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= amount; ++j) {
                dp[i][j] = dp[i - 1][j] + (j >= coins[i] ? dp[i][j - coins[i]] : 0);
            }
        }

        return dp[n - 1][amount];
    }
};

#endif //CPP_518_3_H
