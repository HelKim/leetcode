//
// Created by zhengxiaojian on 2020/12/1.
//

#ifndef CPP_91_H
#define CPP_91_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = s[0] == '0' ? 0 : 1;

        for (int i = 2; i <= n; ++i) {
            if (s[i - 1] != '0') dp[i] = dp[i - 1];
            int t = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (t <= 26 && t > 0 && s[i - 2] != '0') {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};

#endif //CPP_91_H
