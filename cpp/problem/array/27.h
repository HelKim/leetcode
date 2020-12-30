//
// Created by zhengxiaojian on 2020/12/30.
//

#ifndef CPP_27_H
#define CPP_27_H

#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int n = nums.size();
        int  i = 0;
        while (i < n) {
            if (nums[i] == val) {
                transfer(nums, i);
                --n;
            } else ++i;
        }
        return n;
    }

    void transfer(vector<int> &nums, int idx) {
        for (int i = idx + 1; i < nums.size(); ++i) {
            nums[i - 1] = nums[i];
        }
    }
};

#endif //CPP_27_H
