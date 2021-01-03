//
// Created by zhengxiaojian on 2021/1/2.
//

#ifndef CPP_OFFER48_2_H
#define CPP_OFFER48_2_H

#include <vector>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        int p2 = 1, p3 = 1, p5 = 1;

        for (int i = 2; i <= n ; ++i) {
            int s2 = 2 * dp[p2], s3 = 3 * dp[p3], s5 = 5 * dp[p5];
            dp[i] = min(s2, min(s3, s5));
            if (s2 <= dp[i]) ++p2;
            if (s3 <= dp[i]) ++p3;
            if (s5 <= dp[i]) ++p5;
        }

        return dp[n];
    }
};

#endif //CPP_OFFER48_2_H
