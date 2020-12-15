//
// Created by zhengxiaojian on 2020/12/14.
//

#ifndef CPP_77_H
#define CPP_77_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> tmp;

    vector<vector<int>> combine(int n, int k) {
        backtrack(0, n, k);
        return result;
    }

    void backtrack(int s, int n, int k) {
        if (k == 0) {
            result.push_back(tmp);
            return;
        }

        for (int i = s; i < n; ++i) {
            tmp.push_back(i);
            backtrack(i + 1, n, k - 1);
            tmp.pop_back();
        }
    }
};

#endif //CPP_77_H
