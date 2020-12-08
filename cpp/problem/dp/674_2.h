//
// Created by zhengxiaojian on 2020/12/7.
//

#ifndef CPP_674_2_H
#define CPP_674_2_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int ans = 0;
    int countSubstrings(string s) {
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            is(i, i, s);
            is(i, i + 1, s);
        }

        return ans;
    }

    void is(int i, int j, string &s) {
        while (i >= 0 && j < s.size()) {
            if (s[i--] == s[j++]) ++ans;
            else return;
        }
    }
};

#endif //CPP_674_2_H
