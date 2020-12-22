//
// Created by zhengxiaojian on 2020/12/20.
//

#ifndef CPP_394_H
#define CPP_394_H

#include <string>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int idx = 0;
        s = "1[" + s + "]";
        return dfs(idx, s);
    }

    string dfs(int &idx, string &s) {
        if (idx == s.size()) return "";

        int num = 0;
        while (s[idx] >= '0' && s[idx] <= '9') {
            num = num * 10 + s[idx] - '0';
            ++idx;
        }

        string tmp;
        while (idx < s.size() && s[idx] != ']') {
            if (s[idx] == '[') {
                ++idx;
                continue;
            }
            if (s[idx] >= '0' && s[idx] <= '9') {
                tmp += dfs(idx, s);
            } else {
                tmp += s[idx];
            }
            ++idx;
        }

        string res;
        while (num-- > 0) res += tmp;

        return res;
    }
};

#endif //CPP_394_H
