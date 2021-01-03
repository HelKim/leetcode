//
// Created by zhengxiaojian on 2021/1/1.
//

#ifndef CPP_1714_H
#define CPP_1714_H

#include <queue>

using namespace std;

class Solution {
public:
    vector<int> smallestK(vector<int> &arr, int k) {
        priority_queue<int, vector<int>, greater<>> q(arr.begin(), arr.end());
        vector<int> res;
        while (k-- > 0) {
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
};

#endif //CPP_1714_H
