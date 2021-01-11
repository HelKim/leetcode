//
// Created by zhengxiaojian on 2021/1/9.
//

#ifndef CPP_349_H
#define CPP_349_H

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> set;
        for (auto num : nums1) set.insert(num);

        unordered_set<int> res;
        for (auto num : nums2) {
            if (set.count(num)) res.insert(num);
        }

        return vector<int>(res.begin(), res.end());
    }
};

#endif //CPP_349_H
