//
// Created by zhengxiaojian on 2021/1/3.
//

#ifndef CPP_233_H
#define CPP_233_H

class Solution {
public:
    int countDigitOne(int n) {
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += count(i);
        }
        return sum;
    }

    int count(int n) {
        int cnt = 0;
        while (n > 0) {
            if (n % 10 == 1) ++cnt;
            n = n / 10;
        }
        return cnt;
    }
};

#endif //CPP_233_H
