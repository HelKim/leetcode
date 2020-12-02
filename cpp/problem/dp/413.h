//
// Created by zhengxiaojian on 2020/12/2.
//

#ifndef CPP_413_H
#define CPP_413_H

#include <vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &A) {
        int n = A.size();
        if (n < 3) return 0;

        int ans = 0;

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i < n; ++i) {
            dp[i][i + 1] = true;
            for (int j = i + 2; j < n; ++j) {
                dp[i][j] = dp[i][j - 1] && A[j] - A[j - 1] == A[j - 1] - A[j - 2];
                if (dp[i][j]) ++ans;
            }
        }

        return ans;
    }
};

#endif //CPP_413_H
