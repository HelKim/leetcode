//
// Created by zhengxiaojian on 2020/12/2.
//

#ifndef CPP_523_2_H
#define CPP_523_2_H

#include <vector>

using namespace std;

// 状态压缩后AC
class Solution {
public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        int n = nums.size();

        if (n < 2) return false;

        for (int i = 0; i < n; ++i) {
            int pre = nums[i];
            for (int j = i + 1; j < n; ++j) {
                pre += nums[j];
                if (pre == k || (k != 0 && pre % k == 0)) return true;
            }
        }

        return false;
    }
};

#endif //CPP_523_2_H
