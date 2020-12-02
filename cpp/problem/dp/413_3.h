//
// Created by zhengxiaojian on 2020/12/2.
//

#ifndef CPP_413_3_H
#define CPP_413_3_H

#include <vector>

using namespace std;
// 对于长度为n的等差数列（n >= 3), 它有an个子等差数列（包括本身），则an = 2 * an-1 - an-2 + 1
class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &A) {
        int n = A.size();
        if (n < 3) return 0;

        int an1 = 0, an2 = 0;
        int an = 0;
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                an = 2 * an1 - an2 + 1;
                an2 = an1;
                an1 = an;
            } else {
                ans += an;
                an = 0;
                an1 = an2 = 0;
            }
        }

        return ans + an;
    }
};

#endif //CPP_413_3_H
