//
// Created by zhengxiaojian on 2020/12/1.
//

#ifndef CPP_96_H
#define CPP_96_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> dp;

    int numTrees(int n) {
        dp.assign(n + 2, vector<int>(n + 2, -1));
        return numTrees(1, n);
    }

    int numTrees(int s, int e) {
        if (s >= e) return 1;

        int sum = 0;
        for (int i = s; i <= e; ++i) {
            int l = dp[s][i - 1];
            int r = dp[i + 1][e];
            if (l == -1) {
                l = numTrees(s, i - 1);
                dp[s][i - 1] = l;
            }
            if (r == -1) {
                r = numTrees(i + 1, e);
                dp[i + 1][e] = r;
            }
            sum += l * r;
        }

        return sum;
    }
};

#endif //CPP_96_H
