//
// Created by zhengxiaojian on 2020/12/7.
//

#ifndef CPP_647_H
#define CPP_647_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector(n, false));

        int ans = 0;

        for (int l = 1; l <= n; ++l) {
            for (int i = 0; i <= n - l; ++i) {
                int j = i + l - 1;

                if (l == 1) {
                    dp[i][j] = true;
                } else if (l == 2) {
                    dp[i][j] = s[i] == s[j];
                } else {
                    dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
                }

                if (dp[i][j]) ++ans;
            }
        }

        return ans;
    }
};

#endif //CPP_647_H
