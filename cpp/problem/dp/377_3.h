//
// Created by zhengxiaojian on 2020/12/8.
//

#ifndef CPP_377_3_H
#define CPP_377_3_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> memo;

    int combinationSum4(vector<int> &nums, int target) {
        int n = nums.size();
        if (target <= 0 || n == 0) return 0;
        memo.assign(target + 1, -1);
        return backtrack(target, nums);
    }

    int backtrack(int target, vector<int> &nums) {
        if (target < 0) return 0;
        if (target == 0) {
            return 1;
        }
        if (memo[target] == -1) memo[target] = 0;
        else return memo[target];

        for (int i = 0; i < nums.size(); ++i) {
            memo[target] += backtrack(target - nums[i], nums);
        }

        return memo[target];
    }
};

#endif //CPP_377_3_H
