//
// Created by zhengxiaojian on 2020/11/26.
//

#ifndef CPP_10_H
#define CPP_10_H

#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return backtrack(0, 0, s, p);
    }

    bool backtrack(int si, int pi, string &s, string &p) {
        if (si == s.length() && pi == p.length()) return true;
        if (pi == p.length() && si != s.length()) return false;

        switch (p[pi]) {
            case '*':
                return backtrack(si, pi + 1, s, p);
            default:
                if (pi + 1 < p.length() && p[pi + 1] == '*') {
                    if (si < s.length() && (s[si] == p[pi] || p[pi] == '.'))
                        return backtrack(si + 1, pi, s, p) || backtrack(si, pi + 1, s, p);
                    else
                        return backtrack(si, pi + 1, s, p);
                } else {
                    return si < s.length() &&
                           (s[si] == p[pi] || p[pi] == '.') &&
                           backtrack(si + 1, pi + 1, s, p);
                }
        }
    }
};

#endif //CPP_10_H
