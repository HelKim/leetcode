//
// Created by zhengxiaojian on 2021/1/6.
//

#ifndef CPP_398_H
#define CPP_398_H

#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class Solution {
public:
    vector<int> nums;

    Solution(vector<int> &nums) {
        this->nums = nums;
        srand(time(nullptr));
    }

    int pick(int target) {
        int n = 1;
        int select;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != target) continue;
            int r = rand() % n + 1;
            if (r == n) select = i;
            ++n;
        }

        return select;
    }
};

#endif //CPP_398_H
