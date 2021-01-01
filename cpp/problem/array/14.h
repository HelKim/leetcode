//
// Created by zhengxiaojian on 2020/12/31.
//

#ifndef CPP_14_H
#define CPP_14_H

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) return "";

        int n = strs[0].size();
        for (auto &s : strs) n = min(n, (int) s.size());

        string prefix = "";
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[j][i] != strs[j - 1][i]) return prefix;
            }
            prefix += strs[0][i];
        }

        return prefix;
    }
};

#endif //CPP_14_H
