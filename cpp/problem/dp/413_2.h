//
// Created by zhengxiaojian on 2020/12/2.
//

#ifndef CPP_413_2_H
#define CPP_413_2_H

#include <vector>

using namespace std;

//状态压缩
class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &A) {
        int n = A.size();
        if (n < 3) return 0;

        int ans = 0;

        for (int i = 0; i < n; ++i) {
            int dp = true;
            for (int j = i + 2; j < n; ++j) {
                dp = dp && A[j] - A[j - 1] == A[j - 1] - A[j - 2];
                if (dp) ++ans;
            }
        }

        return ans;
    }
};

#endif //CPP_413_2_H
