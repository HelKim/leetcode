//
// Created by zhengxiaojian on 2021/1/2.
//

#ifndef CPP_496_H
#define CPP_496_H

#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        stack<int> s;
        vector<int> res(nums1.size());
        unordered_map<int, int> map;

        for (int i = 0; i < nums2.size(); ++i) {
            while (!s.empty() && s.top() < nums2[i]) {
                map[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }

        while (!s.empty()) {
            map[s.top()] = -1;
            s.pop();
        }

        for (int i = 0; i < nums1.size(); ++i) {
            res[i] = map[nums1[i]];
        }

        return res;
    }
};

#endif //CPP_496_H
