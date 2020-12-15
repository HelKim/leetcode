//
// Created by zhengxiaojian on 2020/12/15.
//

#ifndef CPP_44_H
#define CPP_44_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<bool>> dp(n + 1, vector(m + 1, false));
        dp[0][0] = true;

        for (int si = 1; si < n; ++si) {
            for (int pi = 1; pi < m; ++pi) {
                switch (p[pi - 1]) {
                    case '?':
                        dp[si][pi] = dp[si - 1][pi - 1];
                        break;
                    case '*':
                        dp[si][pi] = dp[si][pi - 1] || dp[si - 1][pi - 1];
                        break;
                    default:
                        dp[si][pi] = s[si - 1] == p[pi - 1] && dp[si - 1][pi - 1];
                        break;
                }
            }
        }

        return dp[n][m];
    }
};

#endif //CPP_44_H
