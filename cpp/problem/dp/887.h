//
// Created by zhengxiaojian on 2021/1/19.
//

#ifndef CPP_887_H
#define CPP_887_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> memo;

    int superEggDrop(int K, int N) {
        memo.assign(K + 1, vector(N + 1, -1));
        return find(K, N);
    }

    int find(int K, int N) {
        if (K == 1) return N;
        if (N == 0) return 0;

        if (memo[K][N] != -1) return memo[K][N];

        int res = INT_MAX / 2;

        for (int i = 1; i <= N; ++i) {
            res = min(res, max(find(K, N - i), find(K - 1, i - 1)) + 1);
        }

        memo[K][N] = res;

        return res;
    }
};

#endif //CPP_887_H
