//
// Created by zhengxiaojian on 2020/12/1.
//

#ifndef CPP_96_3_H
#define CPP_96_3_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dp;

    int numTrees(int n) {
        dp.assign(n + 1, -1);
        return numTrees(1, n);
    }

    int numTrees(int s, int e) {
        if (s >= e) return 1;

        int sum = 0;
        for (int i = s; i <= e; ++i) {
            int l = i == s ? 1 : dp[i - s - 1];
            int r = i == e ? 1 : dp[e - i - 1];
            if (l == -1) {
                l = numTrees(s, i - 1);
                dp[i - s - 1] = l;
            }
            if (r == -1) {
                r = numTrees(i + 1, e);
                dp[e - i - 1] = r;
            }
            sum += l * r;
        }

        return sum;
    }
};

#endif //CPP_96_3_H
