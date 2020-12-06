//
// Created by zhengxiaojian on 2020/12/4.
//

#ifndef CPP_392_H
#define CPP_392_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sn = s.length();
        int tn = t.length();

        if (sn == 0) return true;
        if (tn == 0) return false;

        vector<vector<bool>> dp(sn + 1, vector(tn + 1, false));
        for (int i = 0; i < tn; ++i) dp[0][i] = true;

        for (int i = 1; i < sn; ++i) {
            for (int j = 1; j < tn; ++j) {
                dp[i][j] = dp[i][j - 1] || (dp[i - 1][j - 1] && s[i - 1] == t[j - 1]);
            }
        }

        return dp[sn][tn];
    }
};

#endif //CPP_392_H
