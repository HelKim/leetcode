//
// Created by zhengxiaojian on 2021/1/9.
//

#ifndef CPP_350_H
#define CPP_350_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> map;

        for (auto num : nums1) map[num]++;

        vector<int> res;
        for (auto num : nums2) {
            if (map[num] > 0) {
                map[num]--;
                res.push_back(num);
            }
        }

        return res;
    }
};

#endif //CPP_350_H
