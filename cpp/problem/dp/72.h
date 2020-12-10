//
// Created by zhengxiaojian on 2020/12/8.
//

#ifndef CPP_72_H
#define CPP_72_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector(m + 1, 0));
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= m; ++j) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // dp[i][j - 1] 新增字符，dp[i - 1][j] 删除字符，dp[i - 1][j - 1] 替换字符
                    dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
                }
            }
        }

        return dp[n][m];
    }
};

#endif //CPP_72_H
