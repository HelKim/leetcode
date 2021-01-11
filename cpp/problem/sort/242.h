//
// Created by zhengxiaojian on 2021/1/9.
//

#ifndef CPP_242_H
#define CPP_242_H

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

#endif //CPP_242_H
