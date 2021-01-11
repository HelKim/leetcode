//
// Created by zhengxiaojian on 2021/1/9.
//

#ifndef CPP_38_H
#define CPP_38_H

#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string s = countAndSay(n - 1);
        string res;

        int cnt = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] != s[i - 1]) {
                res.push_back(cnt + '0');
                res.push_back(s[i - 1]);
                cnt = 1;
            } else cnt++;
        }

        res.push_back(cnt + '0');
        res.push_back(s.back());

        return res;
    }
};

#endif //CPP_38_H
