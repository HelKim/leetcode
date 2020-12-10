//
// Created by zhengxiaojian on 2020/12/8.
//

#ifndef CPP_198_2_H
#define CPP_198_2_H

#include <vector>

using namespace std;
// 状态压缩
class Solution {
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int dp0 = nums[0];
        int dp1 = max(nums[0], nums[1]);
        int dp = dp1;
        for (int i = 2; i < n; ++i) {
            dp = max(dp1, dp0 + nums[i]);
            dp0 = dp1;
            dp1 = dp;
        }

        return dp;
    }
};

#endif //CPP_198_2_H
