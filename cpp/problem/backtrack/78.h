//
// Created by zhengxiaojian on 2020/12/14.
//

#ifndef CPP_78_H
#define CPP_78_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> tmp;

    vector<vector<int>> subsets(vector<int> &nums) {
        backtrack(0, nums);
        return result;
    }

    void backtrack(int s, vector<int> &nums) {
        if (s == nums.size()) {
            result.push_back(tmp);
            return;
        }

        backtrack(s + 1, nums);
        tmp.push_back(nums[s]);
        backtrack(s + 1, nums);
        tmp.pop_back();
    }
};

#endif //CPP_78_H
