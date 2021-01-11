//
// Created by zhengxiaojian on 2021/1/9.
//

#ifndef CPP_67_H
#define CPP_67_H

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int bit = 0;

        string res;
        while (i >= 0 || j >= 0 || bit > 0) {
            int x = (i >= 0 ? a[i] - '0' : 0) + (j >= 0 ? b[j] - '0' : 0) + bit;
            bit = x / 2;
            res.push_back((x % 2) + '0');
            --i;
            --j;
        }

        reverse(res.begin(), res.end());

        return res;
    }
};

#endif //CPP_67_H
