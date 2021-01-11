//
// Created by zhengxiaojian on 2021/1/9.
//

#ifndef CPP_268_H
#define CPP_268_H

#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (nums[i] == n) {
                continue;
            }
            if (i != nums[i]) {
                swap(nums[nums[i]], nums[i]);
                --i;
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == n) return i;
        }

        return n;
    }
};

#endif //CPP_268_H
