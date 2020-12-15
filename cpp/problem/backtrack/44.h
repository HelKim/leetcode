//
// Created by zhengxiaojian on 2020/12/15.
//

#ifndef CPP_44_H
#define CPP_44_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector <vector<char>> memo;

    bool isMatch(string s, string p) {
        memo.assign(s.size() + 1, vector(p.size(), (char) -1));
        return backtrack(0, 0, s, p);
    }

    bool backtrack(int si, int pi, string &s, string &p) {
        if (si == s.size() && pi == p.size()) return true;
        if (si > s.size() || pi == p.size()) return false;

        if (memo[si][pi] != -1) return memo[si][pi];

        bool ans;

        switch (p[pi]) {
            case '?':
                ans = backtrack(si + 1, pi + 1, s, p);
                break;
            case '*':
                ans = backtrack(si, pi + 1, s, p) || backtrack(si + 1, pi, s, p);
                break;
            default:
                ans = s[si] == p[pi] && backtrack(si + 1, pi + 1, s, p);
                break;
        }

        memo[si][pi] = ans;
        return ans;
    }
};

#endif //CPP_44_H
