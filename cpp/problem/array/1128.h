//
// Created by zhengxiaojian on 2021/1/26.
//

#ifndef CPP_1128_H
#define CPP_1128_H

class Solution {
public:
    int numEquivDominoPairs(vector <vector<int>> &dominoes) {
        int n = dominoes.size();
        for (int i = 0; i < n; ++i) {
            swap_number(dominoes[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            vector<int> &dominoe1 = dominoes[i];
            for (int j = i + 1; j < n; ++j) {
                vector<int> &dominoe2 = dominoes[j];
                if (dominoe1[0] == dominoe2[0] && dominoe1[1] == dominoe2[1]) ++ans;
            }
        }

        return ans;
    }

    void swap_number(vector<int> &dominoe) {
        if (dominoe[0] > dominoe[1]) swap(dominoe[0], dominoe[1]);
    }
};

#endif //CPP_1128_H
