//
// Created by zhengxiaojian on 2020/12/4.
//

#ifndef CPP_263_H
#define CPP_263_H

class Solution {
public:
    bool isUgly(int num) {
        if (num < 1) return false;

        int base[] = {2, 3, 5};

        int i = 0;
        while (i < 3) {
            if (num % base[i] == 0) num = num / base[i];
            else ++i;
        }

        return num == 1;
    }
};

#endif //CPP_263_H
