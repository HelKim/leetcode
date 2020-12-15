//
// Created by zhengxiaojian on 2020/12/14.
//

#ifndef CPP_46_2_H
#define CPP_46_2_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;

    vector<vector<int>> permute(vector<int> &nums) {
        backtrack(0, nums);
        return result;
    }

    void backtrack(int s, vector<int> &nums) {
        if (s == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = s; i < nums.size(); ++i) {
            swap(nums[s], nums[i]);
            backtrack(i + 1, nums);
            swap(nums[s], nums[i]);
        }
    }
};

#endif //CPP_46_2_H
