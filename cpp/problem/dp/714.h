//
// Created by zhengxiaojian on 2020/12/10.
//

#ifndef CPP_714_H
#define CPP_714_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> memo;

    int maxProfit(vector<int> &prices, int fee) {
        int n = prices.size();
        if (n < 2) return 0;
        memo.assign(n, -1);
        return maxProfit(0, prices, fee);
    }

    int maxProfit(int s, vector<int> &prices, int fee) {
        if (s == prices.size()) return 0;

        if (memo[s] != -1) return memo[s];

        int ans = 0;
        int mmin = prices[s];

        for (int i = s + 1; i < prices.size(); ++i) {
            mmin = min(mmin, prices[i]);
            int cost = prices[i] == mmin ? 0 : prices[i] - mmin - fee;
            ans = max(ans, cost + maxProfit(i + 1, prices, fee));
        }

        memo[s] = ans;

        return ans;
    }
};
#endif //CPP_714_H
