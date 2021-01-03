//
// Created by zhengxiaojian on 2021/1/1.
//

#ifndef CPP_169_H
#define CPP_169_H

#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int major_num = nums[0];
        int cnt = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (cnt == 0) {
                major_num = nums[i];
                ++cnt;
            } else if (major_num != nums[i]) {
                --cnt;
            } else {
                ++cnt;
            }
        }

        return major_num;
    }
};

#endif //CPP_169_H
