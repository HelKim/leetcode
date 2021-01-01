//
// Created by zhengxiaojian on 2021/1/1.
//

#ifndef CPP_45_H
#define CPP_45_H

#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        int n = nums.size();

        vector<int> dp(n, INT_MAX / 2);
        dp[0] = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (j + nums[j] >= i)
                    dp[i] = min(dp[i], dp[j] + 1);
            }
        }

        return dp[n - 1];
    }
};

#endif //CPP_45_H
