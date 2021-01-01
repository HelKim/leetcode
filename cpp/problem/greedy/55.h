//
// Created by zhengxiaojian on 2021/1/1.
//

#ifndef CPP_55_H
#define CPP_55_H

#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int farthest = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            farthest = max(farthest, nums[i] + i);
            if (farthest <= i) break;
        }

        return farthest >= nums.size() - 1;
    }
};

#endif //CPP_55_H
