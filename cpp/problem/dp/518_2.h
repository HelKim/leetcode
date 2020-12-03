//
// Created by zhengxiaojian on 2020/12/3.
//

#ifndef CPP_518_2_H
#define CPP_518_2_H

#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int> &coins) {
        if (amount == 0) return 1;

        int n = coins.size();
        if (n == 0) return 0;

        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= amount; ++j) {
                dp[j] += j >= coins[i] ? dp[j - coins[i]] : 0;
            }
        }

        return dp[amount];
    }
};

#endif //CPP_518_2_H
