//
// Created by zhengxiaojian on 2020/12/9.
//

#ifndef CPP_123_H
#define CPP_123_H

#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ans = 0;
        int n = prices.size();

        for (int i = 0; i < n; ++i) {
            ans = max(maxProfit(0, i - 1, prices) + maxProfit(i, n - 1, prices), ans);
        }
        return ans;
    }

    int maxProfit(int s, int e, vector<int> &prices) {
        int n = e - s + 1;

        if (n < 2) return 0;

        int dp = prices[s];

        int ans = 0;
        for (int i = s; i <= e; ++i) {
            ans = max(ans, prices[i] - dp);
            dp = min(dp, prices[i]);
        }
        return ans;

    };
};

#endif //CPP_123_H
