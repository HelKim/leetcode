//
// Created by zhengxiaojian on 2020/12/10.
//

#ifndef CPP_309_H
#define CPP_309_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> memo;

    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n < 2) return 0;
        memo.assign(n, -1);
        return maxProfit(0, prices);
    }

    int maxProfit(int s, vector<int> &prices) {
        if (s >= prices.size()) return 0;
        if (memo[s] != -1) return memo[s];

        int ans = 0;
        int cur_min = prices[s];
        for (int i = s + 1; i < prices.size(); ++i) {
            cur_min = min(prices[i], cur_min);
            ans = max(ans, prices[i] - cur_min + maxProfit(i + 2, prices));
        }

        memo[s] = ans;

        return ans;
    }
};

#endif //CPP_309_H
