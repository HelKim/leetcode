//
// Created by zhengxiaojian on 2021/1/9.
//

#ifndef CPP_258_H
#define CPP_258_H

class Solution {
public:
    int addDigits(int num) {
        if (num < 10) return num;
        int s = 0;
        while (num > 0) {
            s += num % 10;
            num /= 10;
        }
        return addDigits(s);
    }
};

#endif //CPP_258_H
