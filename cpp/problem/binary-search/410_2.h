//
// Created by zhengxiaojian on 2021/2/2.
//

#ifndef CPP_410_2_H
#define CPP_410_2_H

#include <vector>

using namespace std;

class Solution {
public:
    int splitArray(vector<int> &nums, int m) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector(m + 1, INT_MAX / 2));
        vector<int> sub(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            sub[i + 1] = sub[i] + nums[i];
        }
        dp[0][0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= min(i, m); ++j) {
                for (int k = 0; k < i; ++k) {
                    dp[i][j] = min(dp[i][j], max(dp[k][j - 1], sub[i] - sub[k]));
                }
            }
        }

        return dp[n][m];
    }
};

#endif //CPP_410_2_H
