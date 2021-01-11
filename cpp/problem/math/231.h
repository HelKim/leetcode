//
// Created by zhengxiaojian on 2021/1/9.
//

#ifndef CPP_231_H
#define CPP_231_H

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        int cnt = 0;
        while (n > 0) {
            if ((n & 1) == 1) {
                ++cnt;
                if (cnt > 1) return false;
            }
            n >>= 1;
        }
        return cnt == 1;
    }
};

#endif //CPP_231_H
