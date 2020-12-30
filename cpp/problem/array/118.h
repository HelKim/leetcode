//
// Created by zhengxiaojian on 2020/12/30.
//

#ifndef CPP_118_H
#define CPP_118_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows <= 0) return {};
        vector<vector<int>> res(numRows);
        res[0] = {1};
        for (int i = 1; i < numRows; ++i) {
            for (int j = 0; j <= i; ++j) {
                int s = 1;
                if (j != i && j - 1 >= 0) s = res[i - 1][j] + res[i - 1][j - 1];
                res[i].push_back(s);
            }
        }
        return res;
    }
};

#endif //CPP_118_H
