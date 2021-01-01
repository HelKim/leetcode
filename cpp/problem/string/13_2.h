//
// Created by zhengxiaojian on 2020/12/31.
//

#ifndef CPP_13_2_H
#define CPP_13_2_H

#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> map{{"IV", 4},
                                       {"IX", 9},
                                       {"XL", 40},
                                       {"XC", 90},
                                       {"CD", 400},
                                       {"CM", 900},
                                       {"I",  1},
                                       {"V",  5},
                                       {"X",  10},
                                       {"L",  50},
                                       {"C",  100},
                                       {"D",  500},
                                       {"M",  1000}};

        int sum = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i + 1 < s.size() && map.count(s.substr(i, 2))) {
                sum += map[s.substr(i, 2)];
                ++i;
            } else {
                sum += map[s.substr(i, 1)];
            }
        }

        return sum;
    }
};

#endif //CPP_13_2_H
