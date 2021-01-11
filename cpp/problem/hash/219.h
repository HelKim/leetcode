//
// Created by zhengxiaojian on 2021/1/9.
//

#ifndef CPP_219_H
#define CPP_219_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); ++i) {
            if (map.count(nums[i]) && i - map[nums[i]] <= k)
                return true;
            map[nums[i]] = i;
        }

        return false;
    }
};

#endif //CPP_219_H
