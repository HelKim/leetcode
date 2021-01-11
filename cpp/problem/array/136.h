//
// Created by zhengxiaojian on 2021/1/9.
//

#ifndef CPP_136_H
#define CPP_136_H

#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int s = 0;
        for (auto num : nums) {
            s ^= num;
        }
        return s;
    }
};

#endif //CPP_136_H
