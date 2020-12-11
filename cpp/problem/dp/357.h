//
// Created by zhengxiaojian on 2020/12/10.
//

#ifndef CPP_357_H
#define CPP_357_H

#include <vector>

using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n > 10) return 0;
        vector<int> dp(11, 0);
        dp[0] = 1;
        dp[1] = 10;

        for (int i = 2; i <= n; ++i) {
            dp[i] = (11 - i) * (dp[i - 1] * dp[i - 2]) + dp[i - 1];
        }

        return dp[i];
    }
};

#endif //CPP_357_H
