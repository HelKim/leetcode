//
// Created by zhengxiaojian on 2021/1/21.
//

#ifndef CPP_628_H
#define CPP_628_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[0] * nums[1] * nums[n - 1]);
    }
};

#endif //CPP_628_H
