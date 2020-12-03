//
// Created by zhengxiaojian on 2020/12/3.
//

#ifndef CPP_416_2_H
#define CPP_416_2_H

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int n = nums.size();
        if (n < 2) return false;

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum & 1) == 1) return false;

        int maxNum = *max_element(nums.begin(), nums.end());
        int target = sum >> 1;;

        if (maxNum > target) return false;

        vector<vector<bool>> dp(n, vector(target + 1, false));

        for (int i = 0; i < n; ++i) {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= target; ++j) {
                dp[i][j] = dp[i - 1][j] || (j >= nums[i] && dp[i - 1][j - nums[i]]);
            }
        }

        return dp[n - 1][target];
    }
};

#endif //CPP_416_2_H
