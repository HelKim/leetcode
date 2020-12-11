//
// Created by zhengxiaojian on 2020/12/10.
//

#ifndef CPP_152_H
#define CPP_152_H

#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int n = nums.size();

        pair<int, int> dp = {nums[0], nums[0]};

        int ans = nums[0];

        for (int i = 1; i < n; ++i) {
            int t1 = dp.first * nums[i];
            int t2 = dp.second * nums[i];
            int mmin = min(t1, t2);
            int mmax = max(t1, t2);
            dp = {min(mmin, nums[i]), max(mmax, nums[i])};

            ans = max(dp.second, ans);
        }

        return ans;
    }
};

#endif //CPP_152_H
