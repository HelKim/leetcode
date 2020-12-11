//
// Created by zhengxiaojian on 2020/12/10.
//

#ifndef CPP_120_2_H
#define CPP_120_2_H

#include <vector>

using namespace std;

// 状态压缩
class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int n = triangle.size();
        vector<int> dp(n, 0);

        for (int i = 0; i < n; ++i) {
            dp[i] = triangle[n - 1][i];
        }

        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }

        return dp[0];
    }
};

#endif //CPP_120_2_H
