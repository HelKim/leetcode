//
// Created by zhengxiaojian on 2020/12/15.
//

#ifndef CPP_216_H
#define CPP_216_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> tmp;

    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(1, k, n);
        return result;
    }

    void backtrack(int s, int k, int n) {
        if (k == 0 && n == 0) {
            result.push_back(tmp);
            return;
        }

        if (n < 0) return;

        for (int i = s; i < 10; ++i) {
            tmp.push_back(i);
            backtrack(i + 1, k - 1, n - i);
            tmp.pop_back();
        }
    }
};

#endif //CPP_216_H
