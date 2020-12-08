//
// Created by zhengxiaojian on 2020/12/7.
//

#ifndef CPP_303_H
#define CPP_303_H

#include <vector>

using namespace std;

class NumArray {
public:
    vector<int> dp;
    vector<int> nums;

    NumArray(vector<int> &nums) {
        this->nums = nums;
        int n = nums.size();

        if (n == 0) return;

        dp.assign(n, 0);
        dp[0] = nums[0];

        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i - 1] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        return dp[j] - dp[i];
    }
};

#endif //CPP_303_H
