//
// Created by zhengxiaojian on 2020/12/9.
//

#ifndef CPP_121_H
#define CPP_121_H

#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();

        if (n == 0 || n == 1) return 0;

        vector<int> dp(n, 0);
        dp[0] = prices[0];
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            ans = max(ans, prices[i] - dp[i - 1]);
            dp[i] = min(dp[i - 1], prices[i]);
        }
        return ans;
    }
};

#endif //CPP_121_H
