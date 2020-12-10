//
// Created by zhengxiaojian on 2020/12/8.
//

#ifndef CPP_377_H
#define CPP_377_H

#include <vector>

using namespace std;
// 先用回溯法（377_2），接着记忆化优化（377_3），最后根据记忆化回溯写出动态规划，不然这个递推方程不太容易想得出来。
class Solution {
public:
    int combinationSum4(vector<int> &nums, int target) {
        int n = nums.size();
        if (target <= 0 || n == 0) return 0;

        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= target; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i - nums[j] >= 0) dp[i] += dp[i - nums[j]];
            }
        }

        return dp[target];
    }
};

#endif //CPP_377_H
