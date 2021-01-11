//
// Created by zhengxiaojian on 2021/1/9.
//

#ifndef CPP_28_H
#define CPP_28_H

#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (haystack.empty()) return -1;

        int end = haystack.size() - needle.size();
        for (int i = 0; i <= end; ++i) {
            if (haystack[i] == needle[0]) {
                int j;
                for (j = 0; j < needle.size(); ++j) {
                    if (haystack[i + j] != needle[j]) break;
                }
                if (j == needle.size()) return i;
            }
        }

        return -1;
    }
};

#endif //CPP_28_H
