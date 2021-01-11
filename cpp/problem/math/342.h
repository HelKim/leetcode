//
// Created by zhengxiaojian on 2021/1/9.
//

#ifndef CPP_342_H
#define CPP_342_H

class Solution {
public:
    bool isPowerOfFour(int n) {
        while (n > 1) {
            if (n % 4 != 0) return false;
            n /= 4;
        }
        return n == 1;
    }
};

#endif //CPP_342_H
