//
// Created by zhengxiaojian on 2021/1/9.
//

#ifndef CPP_283_H
#define CPP_283_H

#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int zero_cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                ++zero_cnt;
                continue;
            }
            nums[i + zero_cnt] = nums[i];
        }
        for (int i = nums.size() - zero_cnt; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};

#endif //CPP_283_H
