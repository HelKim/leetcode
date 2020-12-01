//
// Created by zhengxiaojian on 2020/12/1.
//

#ifndef CPP_70_H
#define CPP_70_H

#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int dp1 = 1;
        int dp2 = 1;
        int t;

        for (int i = 2; i <= n; ++i) {
            t = dp2;
            dp2 += dp1;
            dp1 = t;
        }

        return dp2;
    }
};

#endif //CPP_70_H
