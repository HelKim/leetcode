//
// Created by zhengxiaojian on 2020/12/6.
//

#ifndef CPP_343_H
#define CPP_343_H
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;

        int d = n % 3;
        int k = n / 3;
        if (d == 0) return pow(3, k);
        if (d == 1) return pow(3, k - 1) * 4;
        if (d == 2) return pow(3, k) * 2;

        return 0;
    }
};

#endif //CPP_343_H
