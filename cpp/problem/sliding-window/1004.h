//
// Created by zhengxiaojian on 2021/1/6.
//

#ifndef CPP_1004_H
#define CPP_1004_H

#include <vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int> &A, int K) {
        int left = 0, right = 0;
        int cnt = 0;

        while (right < A.size()) {
            if (A[right++] == 1) ++cnt;
            if (right - left > K + cnt) {
                if (A[left] == 1) --cnt;
                ++left;
            }
        }

        return right - left;
    }
};

#endif //CPP_1004_H
