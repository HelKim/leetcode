//
// Created by zhengxiaojian on 2020/12/10.
//

#ifndef CPP_714_3_H
#define CPP_714_3_H

#include <vector>

using namespace std;

// 状态压缩
class Solution {
public:
    int maxProfit(vector<int> &prices, int fee) {
        int n = prices.size();
        if (n < 2) return 0;

        int dp0 = 0;
        int dp1 = -prices[0];
        for (int i = 1; i < n; ++i) {
            int ndp0 = max(dp0, dp1 + prices[i] - fee);
            int ndp1 = max(dp1, dp0 - prices[i]);
            dp0 = ndp0;
            dp1 = ndp1;
        }
        return dp0;
    }
};

#endif //CPP_714_3_H
