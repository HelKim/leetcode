//
// Created by zhengxiaojian on 2021/1/9.
//

#ifndef CPP_204_H
#define CPP_204_H

#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                ans++;
                if ((long long )i * i < n) {
                    for (int j = i * i; j < n; j += i) {
                        isPrime[j] = false;
                    }
                }
            }
        }
        return ans;
    }
};

#endif //CPP_204_H
