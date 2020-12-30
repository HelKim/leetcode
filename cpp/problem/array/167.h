//
// Created by zhengxiaojian on 2020/12/30.
//

#ifndef CPP_167_H
#define CPP_167_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        while (l < r) {
            int s = numbers[l] + numbers[r];

            if (s == target) {
                return {l + 1, r + 1};
            }
            if (s < target) ++l;
            else --r;
        }
        return {};
    }
};

#endif //CPP_167_H
