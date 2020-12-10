//
// Created by zhengxiaojian on 2020/12/9.
//

#ifndef CPP_123_2_H
#define CPP_123_2_H

#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();

        vector<int> dp1(n, 0);
        int mmin = prices[0];
        for (int i = 1; i < n; ++i) {
            dp1[i] = max(dp1[i], prices[i] - mmin);
            mmin = min(prices[i], mmin);
        }

        vector<int> dp2(n, 0);
        int mmax = prices[n - 1];
        for (int j = n - 2; j >= 0; --j) {
            dp2[j] = max(dp2[j + 1], mmax - prices[j]);
            mmax = max(prices[j], mmax);
        }

        int ans = dp1[n - 1];
        for (int i = 1; i < n; ++i) {
            ans = max(dp1[i - 1] + dp2[i], ans);
        }
        return ans;
    }

};

#endif //CPP_123_2_H
