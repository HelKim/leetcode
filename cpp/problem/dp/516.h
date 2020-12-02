//
// Created by zhengxiaojian on 2020/12/2.
//

#ifndef CPP_516_H
#define CPP_516_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector(n, 0));

        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }

        for (int l = 2; l <= n; ++l) {
            for (int i = 0; i <= n - l; ++i) {
                int j = i + l - 1;
                if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
                else dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
        return dp[0][n - 1];
    }
};

#endif //CPP_516_H
