//
// Created by zhengxiaojian on 2021/1/1.
//

#ifndef CPP_45_3_H
#define CPP_45_3_H

#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        int n = nums.size();
        int end = 0, farthest = 0;
        int jumps = 0;
        for (int i = 0; i < n - 1; ++i) {
            farthest = max(farthest, i + nums[i]);
            if (i == end) {
                jumps++;
                end = farthest;
            }
        }
        return jumps;
    }
};

#endif //CPP_45_3_H
