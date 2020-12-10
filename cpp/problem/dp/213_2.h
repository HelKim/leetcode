//
// Created by zhengxiaojian on 2020/12/8.
//

#ifndef CPP_213_2_H
#define CPP_213_2_H

#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);


        return max(rob1(vector(nums.begin(), nums.end() - 1)), rob1(vector(nums.begin() + 1, nums.end())));
    }

    int rob1(vector<int> nums) {
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

#endif //CPP_213_2_H
