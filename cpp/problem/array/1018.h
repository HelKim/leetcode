//
// Created by zhengxiaojian on 2021/1/14.
//

#ifndef CPP_1018_H
#define CPP_1018_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int> &A) {
        vector<bool> res;
        int n = 0;
        for (int i = 0; i < A.size(); ++i) {
            n = n * 2 + A[i];
            res.push_back(n % 5 == 0);
            n %= 5;
        }
        return res;
    }
};

#endif //CPP_1018_H
