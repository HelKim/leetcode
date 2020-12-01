//
// Created by zhengxiaojian on 2020/12/1.
//

#ifndef CPP_368_H
#define CPP_368_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        if (nums.empty()) return {};

        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(0));
        vector<int> ans = dp[0] = {nums[0]};

        for (int i = 1; i < n; ++i) {
            dp[i] = {nums[i]};
            for (int j = i - 1; j >= 0; --j) {
                if (nums[i] % nums[j] == 0 && dp[i].size() < dp[j].size() + 1) {
                    dp[i] = dp[j];
                    dp[i].push_back(nums[i]);
                    if (dp[i].size() > ans.size()) ans = dp[i];
                }
            }
        }

        return ans;
    }
};

#endif //CPP_368_H
