//
// Created by zhengxiaojian on 2020/12/8.
//

#ifndef CPP_213_H
#define CPP_213_H

#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        vector <vector<int>> dp(n, vector(n, 0));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = nums[i];
        }
        for (int i = 0; i < n - 1; ++i) {
            dp[i][i + 1] = max(nums[i], nums[i + 1]);
        }

        for (int l = 3; l <= n; ++l) {
            for (int i = 0; i <= n - l; ++i) {
                int j = i + l - 1;
                dp[i][j] = max(dp[i][j - 1], dp[i][j - 2] + nums[j]);
            }
        }

        return max(dp[0][n - 2], dp[1][n - 1]);
    }
};

#endif //CPP_213_H
