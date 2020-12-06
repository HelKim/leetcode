//
// Created by zhengxiaojian on 2020/12/6.
//

#ifndef CPP_343_2_H
#define CPP_343_2_H

#include <vector>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = dp[2] = 1;

        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }

        return dp[n];
    }
};

#endif //CPP_343_2_H
