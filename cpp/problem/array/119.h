//
// Created by zhengxiaojian on 2020/12/30.
//

#ifndef CPP_119_H
#define CPP_119_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 1);
        vector<int> pre(rowIndex + 1, 1);
        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = 1; j < i; ++j) {
                res[j] = pre[j] + pre[j - 1];
            }
            pre = res;
        }

        return pre;
    }
};

#endif //CPP_119_H
