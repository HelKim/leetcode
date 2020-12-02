//
// Created by zhengxiaojian on 2020/12/2.
//

#ifndef CPP_523_H
#define CPP_523_H

#include <vector>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        int n = nums.size();

        if (n < 2) return false;

        vector<vector<int>> dp(n, vector(n, 0));

        for (int i = 0; i < n; ++i) {
            dp[i][i] = nums[i];
        }

        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                dp[i][j] = dp[i][j - 1] + nums[j];
                if (k == dp[i][j] || (k != 0 && dp[i][j] % k == 0)) return true;
            }
        }

        return false;
    }
};

#endif //CPP_523_H
