//
// Created by zhengxiaojian on 2021/1/9.
//

#ifndef CPP_125_H
#define CPP_125_H

#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() < 2) return true;

        int i = 0, j = s.size() - 1;

        while (i < j) {
            if (!isalpha(s[i]) && !isdigit(s[i])) {
                ++i;
                continue;
            }
            if (!isalpha(s[j]) && !isdigit(s[j])) {
                --j;
                continue;
            }
            if (toupper(s[i]) != toupper(s[j])) return false;
            ++i;
            --j;
        }

        return true;
    }
};

#endif //CPP_125_H
