//
// Created by zhengxiaojian on 2020/10/9.
//

#ifndef CPP_96_H
#define CPP_96_H

#include <vector>

using namespace std;

class Solution {
public: 
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        
        return dp[n];
    }
};

#endif //CPP_96_H
