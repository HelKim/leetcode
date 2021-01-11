//
// Created by zhengxiaojian on 2021/1/9.
//

#ifndef CPP_172_H
#define CPP_172_H

class Solution {
public:
    int trailingZeroes(int n) {
        int s = 0;
        while (n > 0) {
            s += n / 5;
            n = n / 5;
        }
        return s;
    }
};

#endif //CPP_172_H
