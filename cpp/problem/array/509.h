//
// Created by zhengxiaojian on 2021/1/4.
//

#ifndef CPP_509_H
#define CPP_509_H

class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1) return n;

        int ppre = 0, pre = 1;
        int cur;

        for (int i = 2; i <= n; ++i) {
            cur = ppre + pre;
            ppre = pre;
            pre = cur;
        }

        return cur;
    }
};

#endif //CPP_509_H
