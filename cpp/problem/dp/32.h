//
// Created by zhengxiaojian on 2020/11/30.
//

#ifndef CPP_32_H
#define CPP_32_H

#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int ans = 0;

        vector<int> dp(n, 0);

        for (int i = 1; i < n; ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1] >= 2) ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
            }
            ans = max(dp[i], ans);
        }

        return ans;
    }
};

#endif //CPP_32_H
