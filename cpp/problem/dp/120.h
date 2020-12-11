//
// Created by zhengxiaojian on 2020/12/10.
//

#ifndef CPP_120_H
#define CPP_120_H

#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector(n, 0));

        for (int i = 0; i < n; ++i) {
            dp[n - 1][i] = triangle[n - 1][i];
        }

        for (int i = n - 2; i >= 0; ++i) {
            for (int j = 0; j <= i; ++j) {
                dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
            }
        }

        return dp[0][0];
    }
};

#endif //CPP_120_H
