//
// Created by zhengxiaojian on 2021/1/2.
//

#ifndef CPP_9_H
#define CPP_9_H

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;

        int bit_cnt = count(x);
        int num = 0;

        int k = bit_cnt / 2;
        while (k-- > 0) {
            num = num * 10 + x % 10;
            x /= 10;
        }
        if ((bit_cnt & 1) == 1) x /= 10;

        return x == num;
    }

    int count(int x) {
        int cnt = 1;
        while ((x = x / 10) > 0) ++cnt;
        return cnt;
    }
};

#endif //CPP_9_H
