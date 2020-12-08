//
// Created by zhengxiaojian on 2020/12/7.
//

#ifndef CPP_494_2_H
#define CPP_494_2_H

#include <vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int S) {
        S = abs(S);
        if (S > 1000) return 0;
        int n = nums.size();
        vector<vector<int>> dp(n, vector(1001, 0));
        dp[0][nums[0]] += 1;
        if (nums[0] == 0) dp[0][0] += 1;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= 1000; ++j) {
                if (abs(j - nums[i]) <= 1000)
                    dp[i][j] += dp[i - 1][abs(j - nums[i])];
                if (j + nums[i] <= 1000)
                    dp[i][j] += dp[i - 1][j + nums[i]];
            }
        }

        return dp[n - 1][S];
    }
};

#endif //CPP_494_2_H
