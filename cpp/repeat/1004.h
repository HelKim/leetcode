//
// Created by zhengxiaojian on 2021/2/19.
//

#ifndef CPP_1004_H
#define CPP_1004_H

#include <vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int> &A, int K) {
        int left = 0, right = 0;
        int zeroNum = 0;

        while (right < A.size()) {
            if (A[right++] == 0) zeroNum++;
            if (zeroNum > K && A[left++] == 0) zeroNum--;
        }

        return right - left;
    }
};

#endif //CPP_1004_H
