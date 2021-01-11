//
// Created by zhengxiaojian on 2021/1/9.
//

#ifndef CPP_922_H
#define CPP_922_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int> &A) {
        int odd = 1, even = 0;
        int n = A.size();

        while (odd < n && even < n) {
            while (odd < n && (A[odd] & 1) == 1) odd += 2;
            while (even < n && (A[even] & 1) == 0) even += 2;

            if (odd < n && even < n) {
                swap(A[odd], A[even]);
            }
        }

        return A;
    }
};

#endif //CPP_922_H
