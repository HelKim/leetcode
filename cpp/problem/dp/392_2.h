//
// Created by zhengxiaojian on 2020/12/4.
//

#ifndef CPP_392_2_H
#define CPP_392_2_H
#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sn = s.length();
        int tn = t.length();

        int i = 0, j = 0;
        while (i < sn && j < tn) {
            if (s[i] == t[j]) ++i;
            ++j;
        }

        return i == sn;
    }
};
#endif //CPP_392_2_H
