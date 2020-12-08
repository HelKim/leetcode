//
// Created by zhengxiaojian on 2020/12/7.
//

#ifndef CPP_338_H
#define CPP_338_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1, 0);
        for (int i = 1; i <= num; ++i) {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }
};;

#endif //CPP_338_H
