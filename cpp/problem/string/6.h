//
// Created by zhengxiaojian on 2020/12/31.
//

#ifndef CPP_6_H
#define CPP_6_H

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<vector<char>> v(numRows);
        int idx = 0;
        int extra = 1;
        for (char c : s) {
            v[idx].push_back(c);
            if (idx == 0 && extra == -1) {
                extra = 1;
            }
            if (idx == numRows - 1 && extra == 1) {
                extra = -1;
            }
            idx += extra;
        }

        string res;
        for (auto &item : v) {
            for (auto c : item) {
                res.push_back(c);
            }
        }

        return res;
    }
};

#endif //CPP_6_H
