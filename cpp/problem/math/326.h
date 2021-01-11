//
// Created by zhengxiaojian on 2021/1/9.
//

#ifndef CPP_326_H
#define CPP_326_H

class Solution {
public:
    bool isPowerOfThree(int n) {
        while (n > 1) {
            if (n % 3 != 0) return false;
            n /= 3;
        }
        return n == 1;
    }
};

#endif //CPP_326_H
