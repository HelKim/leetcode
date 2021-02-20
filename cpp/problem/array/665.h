//
// Created by zhengxiaojian on 2021/2/7.
//

#ifndef CPP_665_H
#define CPP_665_H

#include <vector>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int> &nums) {
        int diff = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                if (i == 0) nums[i] = nums[i + 1];
                else if (nums[i - 1] > nums[i + 1]) nums[i + 1] = nums[i];
                else nums[i] = nums[i - 1];
                ++diff;
            }
        }
        return diff <= 1;
    }
};

#endif //CPP_665_H
