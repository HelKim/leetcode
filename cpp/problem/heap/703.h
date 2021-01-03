//
// Created by zhengxiaojian on 2021/1/3.
//

#ifndef CPP_703_H
#define CPP_703_H

#include <vector>
#include <algorithm>

using namespace std;

class KthLargest {
public:
    int k;
    vector<int> nums;

    KthLargest(int k, vector<int> &nums) {
        this->k = k;
        this->nums = nums;
        sort(this->nums.begin(), this->nums.end());
    }

    int add(int val) {
        nums.push_back(val);
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] > val) {
            nums[i + 1] = nums[i];
            --i;
        }
        nums[i + 1] = val;
        return nums[nums.size() - k];
    }
};

#endif //CPP_703_H
