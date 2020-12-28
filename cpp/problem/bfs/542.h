//
// Created by zhengxiaojian on 2020/12/27.
//

#ifndef CPP_542_H
#define CPP_542_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector <vector<int>> updateMatrix(vector <vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector <vector<int>> dp(n, vector(m, 0x3f3f3f3f));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 0) dp[i][j] = 0;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 0) continue;

                if (i - 1 >= 0)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                if (j - 1 >= 0)
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (matrix[i][j] == 0) continue;

                if (i + 1 < n)
                    dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                if (j + 1 < m)
                    dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
            }
        }

        return dp;
    }
};

#endif //CPP_542_H
