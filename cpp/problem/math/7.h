//
// Created by zhengxiaojian on 2021/1/2.
//

#ifndef CPP_7_H
#define CPP_7_H

#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x >= 0) {
            auto v = rev(x);
            return v > INT_MAX ? 0 : (int) v;
        } else {
            auto v = -rev(x);
            return v < INT_MIN ? 0 : (int) v;
        }
    }

    long long rev(int x) {
        string s = to_string(x);
        reverse(s.begin(), s.end());
        return stoll(s.begin(), s.end());
    }
};

#endif //CPP_7_H
