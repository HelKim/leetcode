//
// Created by zhengxiaojian on 2021/2/1.
//

#ifndef CPP_888_H
#define CPP_888_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int> &A, vector<int> &B) {
        int sumA = 0, sumB = 0;

        for (auto a : A) {
            sumA += a;
        }

        for (auto b : B) {
            sumB += b;
        }

        int diff = (sumA - sumB) / 2;
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int i = 0, j = 0;
        while (i < A.size() && j < B.size()) {
            int sub = A[i] - B[j];
            if (sub == diff) return {A[i], B[j]};
            if (sub > diff) ++j;
            else ++i;
        }

        return {};
    }
};

#endif //CPP_888_H
