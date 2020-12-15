//
// Created by zhengxiaojian on 2020/12/13.
//

#ifndef CPP_217_H
#define CPP_217_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_map<int, int> map;
        for (auto num : nums) {
            if (map.find(num) == map.end()) {
                map[num] = 0;
            }
            ++map[num];
            if (map[num] > 1) return true;
        }
        return false;
    }
};

#endif //CPP_217_H
