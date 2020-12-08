//
// Created by zhengxiaojian on 2020/12/6.
//

#ifndef CPP_494_H
#define CPP_494_H

#include <vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int S) {
        if (S > 1000 || S < -1000) return 0;
        int n = nums.size();
        vector<vector<int>> dp(n, vector(2001, 0));
        dp[0][nums[0] + 1000] += 1;
        dp[0][1000 - nums[0]] += 1;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= 2000; ++j) {
                if (j - nums[i] >= 0)
                    dp[i][j] += dp[i - 1][j - nums[i]];
                if (j + nums[i] <= 2000)
                    dp[i][j] += dp[i - 1][j + nums[i]];
            }
        }

        return dp[n - 1][S + 1000];
    }
};

#endif //CPP_494_H
