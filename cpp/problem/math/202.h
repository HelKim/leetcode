//
// Created by zhengxiaojian on 2021/1/9.
//

#ifndef CPP_202_H
#define CPP_202_H

#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;

        while (!set.count(n)) {
            set.insert(n);

            int num = 0;
            while (n > 0) {
                int b = n % 10;
                n /= 10;
                num += b * b;
            }

            if (num == 1) return true;

            n = num;
        }

        return false;
    }
};

#endif //CPP_202_H
