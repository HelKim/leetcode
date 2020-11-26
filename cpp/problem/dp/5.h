//
// Created by zhengxiaojian on 2020/11/25.
//

#ifndef CPP_5_H
#define CPP_5_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length()));

        int maxi = 0;
        int maxj = 0;
        for (int l = 0; l < s.length(); ++l) {
            for (int i = 0; i < s.length() - l; ++i) {
                int j = i + l;
                if (l == 0) {
                    dp[i][j] = true;
                } else if (l == 1) {
                    dp[i][j] = s[i] == s[j];
                } else {
                    dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
                }
                if (dp[i][j] && j - i > maxj - maxi) {
                    maxj = j;
                    maxi = i;
                }
            }
        }

        return s.substr(maxi, maxj - maxi + 1);
    }
};

#endif //CPP_5_H
