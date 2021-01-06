//
// Created by zhengxiaojian on 2021/1/5.
//

#ifndef CPP_830_H
#define CPP_830_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector <vector<int>> largeGroupPositions(string s) {
        if (s.size() <= 2) return {};
        vector <vector<int>> res;

        int i = 0, j = 1;
        while (j < s.size()) {
            if (s[i] != s[j]) {
                if (j - i >= 3) {
                    res.push_back({i, j - 1});
                }
                i = j;
            }
            ++j;
        }

        if (j - i >= 3) res.push_back({i, j - 1});

        return res;
    }
};

#endif //CPP_830_H
