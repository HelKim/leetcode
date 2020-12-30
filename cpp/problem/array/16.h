//
// Created by zhengxiaojian on 2020/12/30.
//

#ifndef CPP_16_H
#define CPP_16_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int min_diff = INT_MAX;

        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == target) return target;
                int diff = abs(target - sum);
                if (diff < min_diff) {
                    ans = sum;
                    min_diff = diff;
                }
                if (sum < target) ++l;
                else --r;
            }
        }

        return ans;
    }
};

#endif //CPP_16_H
