//
// Created by zhengxiaojian on 2020/12/15.
//

#ifndef CPP_90_2_H
#define CPP_90_2_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> tmp;

    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        backtrack(0, nums);
        return result;
    }

    void backtrack(int s, vector<int> &nums) {
        result.push_back(tmp);

        for (int i = s; i < nums.size(); ++i) {
            if (i > s && nums[i] == nums[i - 1]) continue;

            tmp.push_back(nums[i]);
            backtrack(s + 1, nums);
            tmp.pop_back();
        }
    }
};

#endif //CPP_90_2_H
