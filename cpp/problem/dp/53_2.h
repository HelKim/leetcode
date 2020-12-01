//
// Created by zhengxiaojian on 2020/12/1.
//

#ifndef CPP_53_2_H
#define CPP_53_2_H

#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int n = nums.size();
        int ans = nums[0];
        int dp = nums[0];

        for (int i = 1; i < n; ++i) {
            dp = max(dp + nums[i], nums[i]);
            ans = max(ans, dp);
        }

        return ans;
    }
};

#endif //CPP_53_2_H
