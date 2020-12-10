//
// Created by zhengxiaojian on 2020/12/9.
//

#ifndef CPP_188_2_H
#define CPP_188_2_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> memo;

    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        if (k == 0 || n < 2) return 0;
        memo.assign(n, vector(k + 1, -1));

        return maxProfit(0, k, prices);
    }

    int maxProfit(int s, int k, vector<int> &prices) {
        if (k == 0 || s >= prices.size()) return 0;
        if (memo[s][k] != -1) return memo[s][k];

        int mmin = prices[s];
        int ans = 0;
        for (int i = s + 1; i < prices.size(); ++i) {
            mmin = min(mmin, prices[i]);
            ans = max(ans, prices[i] - mmin + maxProfit(i + 1, k - 1, prices));
        }
        memo[s][k] = ans;
        return ans;
    }
};

#endif //CPP_188_2_H
