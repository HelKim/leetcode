//
// Created by zhengxiaojian on 2021/1/3.
//

#ifndef CPP_233_2_H
#define CPP_233_2_H

#include <vector>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        vector<int> dp(n + 1);
        dp[0] = 0;
        int sum = 0;

        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i / 10] + (i % 10 == 1 ? 1 : 0);
            sum += dp[i];
        }

        return sum;
    }
};

#endif //CPP_233_2_H
