//
// Created by zhengxiaojian on 2020/12/9.
//

#ifndef CPP_121_2_H
#define CPP_121_2_H

#include <vector>

using namespace std;
// 状态压缩
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();

        if (n == 0 || n == 1) return 0;

        int dp = prices[0];

        int ans = 0;
        for (int i = 1; i < n; ++i) {
            ans = max(ans, prices[i] - dp);
            dp = min(dp, prices[i]);
        }
        return ans;
    }
};

#endif //CPP_121_2_H
