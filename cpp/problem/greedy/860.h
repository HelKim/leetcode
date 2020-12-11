//
// Created by zhengxiaojian on 2020/12/10.
//

#ifndef CPP_860_H
#define CPP_860_H
using namespace std;

#include <vector>

class Solution {
public:
    bool lemonadeChange(vector<int> &bills) {
        int b5 = 0, b10 = 0;

        for (auto bill : bills) {
            switch (bill) {
                case 5:
                    b5++;
                    break;
                case 10:
                    b10++;
                    b5--;
                    break;
                case 20:
                    if (b10 > 0) b10--;
                    else b5 -= 2;
                    b5--;
                    break;
            }
            if (b5 < 0 || b10 < 0) return false;
        }

        return true;
    }
};

#endif //CPP_860_H
