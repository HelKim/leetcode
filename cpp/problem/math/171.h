//
// Created by zhengxiaojian on 2021/1/9.
//

#ifndef CPP_171_H
#define CPP_171_H

#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        unsigned int sum = 0;
        for (int i = 0; i < s.size(); ++i) {
            sum = sum * 26 + s[i] - 'A' + 1;
        }
        return sum;
    }
};

#endif //CPP_171_H
