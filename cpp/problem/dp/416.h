//
// Created by zhengxiaojian on 2020/12/3.
//

#ifndef CPP_416_H
#define CPP_416_H

#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector <vector<char>> memo;

    bool canPartition(vector<int> &nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if ((sum & 1) == 1) return false;

        sum = sum >> 1;

        memo.assign(nums.size(), vector(sum + 1, (char) 0));
        return backtrack(0, sum, nums);
    }

    bool backtrack(int start, int target, vector<int> &nums) {
        if (start == nums.size() || target < 0) return false;
        if (target == 0 ) return true;

        if (memo[start][target] != 0) return memo[start][target] == 1;

        for (int i = start; i < nums.size(); ++i) {
            if (backtrack(i + 1, target - nums[i], nums)) {
                memo[i][target] = 1;
                return true;
            }
        }

        memo[start][target] = 2;

        return false;
    }
};

#endif //CPP_416_H
