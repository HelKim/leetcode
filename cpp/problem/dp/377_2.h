//
// Created by zhengxiaojian on 2020/12/8.
//

#ifndef CPP_377_2_H
#define CPP_377_2_H

#include <vector>

using namespace std;

class Solution {
public:
    int s = 0;

    int combinationSum4(vector<int> &nums, int target) {
        int n = nums.size();
        if (target <= 0 || n == 0) return 0;
        backtrack(target, nums);
        return s;
    }

    void backtrack(int target, vector<int> &nums) {
        if (target < 0) return;
        if (target == 0) {
            ++s;
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            backtrack(target - nums[i], nums);
        }
    }
};

#endif //CPP_377_2_H
