//
// Created by zhengxiaojian on 2021/1/3.
//

#ifndef CPP_233_3_H
#define CPP_233_3_H

class Solution {
public:
    int countDigitOne(int n) {
        int cnt = 0;
        for (long long i = 1; i <= n; i *= 10) {
            long long divider = i * 10;
            cnt += (n / divider) * i + min(max(n % divider - i + 1, 0LL), i);
        }
        return cnt;
    }
};

#endif //CPP_233_3_H
