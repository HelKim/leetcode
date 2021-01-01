//
// Created by zhengxiaojian on 2020/12/30.
//

#ifndef CPP_13_H
#define CPP_13_H

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (i + 1 < s.size() && get(s[i]) < get(s[i + 1])) sum -= get(s[i]);
            else sum += get(s[i]);
        }
        return sum;
    }

    int get(char c) {
        switch (c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }
};

#endif //CPP_13_H
