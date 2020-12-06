//
// Created by zhengxiaojian on 2020/12/6.
//

#ifndef CPP_264_2_H
#define CPP_264_2_H
using namespace std;

#include <vector>

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<unsigned long long> dp(n, 0);
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;

        for (int i = 1; i < n; ++i) {
            dp[i] = min(dp[p2] * 2, min(dp[p3] * 3, dp[p5] * 5));
            if (dp[p2] * 2 == dp[i]) ++p2;
            if (dp[p3] * 3 == dp[i]) ++p3;
            if (dp[p5] * 5 == dp[i]) ++p5;
        }

        return dp[n - 1];
    }
};

#endif //CPP_264_2_H
