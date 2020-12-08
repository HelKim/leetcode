//
// Created by zhengxiaojian on 2020/12/7.
//

#ifndef CPP_494_3_H
#define CPP_494_3_H

#include <vector>

using namespace std;

class Solution {
public:
    int sum = 0;

    int findTargetSumWays(vector<int> &nums, int S) {
        if (S > 1000 || S < -1000) return 0;
        backtrack(0, 0, S, nums);
        return sum;
    }

    void backtrack(int start, int s, int S, vector<int> &nums) {
        if (start == nums.size()) {
            if (s == S) ++sum;
            return;
        }

        backtrack(start + 1, s + nums[start], S, nums);
        backtrack(start + 1, s - nums[start], S, nums);
    }
};

#endif //CPP_494_3_H
