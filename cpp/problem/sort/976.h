//
// Created by zhengxiaojian on 2021/1/9.
//

#ifndef CPP_976_H
#define CPP_976_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int> &A) {
        sort(A.begin(), A.end());

        for (int i = A.size() - 1; i >= 2; --i) {
            if (A[i - 1] + A[i - 2] > A[i]) return A[i] + A[i - 1] + A[i - 2];
        }

        return 0;
    }
};

#endif //CPP_976_H
