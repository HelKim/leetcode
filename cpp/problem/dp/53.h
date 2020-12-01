//
// Created by zhengxiaojian on 2020/12/1.
//

#ifndef CPP_53_H
#define CPP_53_H

#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int n = nums.size();
        int ans = nums[0];

        vector<int> dp(n, 0);
        dp[0] = nums[0];

        for (int i = 1; i < n; ++i) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};

#endif //CPP_53_H
