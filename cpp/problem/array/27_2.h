//
// Created by zhengxiaojian on 2020/12/30.
//

#ifndef CPP_27_2_H
#define CPP_27_2_H

#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int n = nums.size() - 1;
        int i = 0;
        while (i <= n) {
            if (nums[i] == val) {
                nums[i] = nums[n--];
            } else ++i;
        }
        return n + 1;
    }
};

#endif //CPP_27_2_H
