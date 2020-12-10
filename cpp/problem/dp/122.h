//
// Created by zhengxiaojian on 2020/12/9.
//

#ifndef CPP_122_H
#define CPP_122_H

#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0 || n == 1) return 0;

        int l = 0, r;
        int ans = 0;

        while (l + 1 < n) {
            while (l + 1 < n && prices[l] > prices[l + 1]) ++l;
            r = l + 1;
            while (r + 1 < n && prices[r] < prices[r + 1]) ++r;
            if (r < n) ans += prices[r] - prices[l];
            l = r + 1;
        }

        return ans;
    }
};

#endif //CPP_122_H
