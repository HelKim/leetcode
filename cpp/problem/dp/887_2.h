//
// Created by zhengxiaojian on 2021/1/21.
//

#ifndef CPP_887_2_H
#define CPP_887_2_H

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

        int lo = 1, hi = N;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int broken = find(K - 1, mid - 1);
            int not_broken = find(K, N - mid);

            if (broken > not_broken) {
                hi = mid - 1;
                res = min(res, broken + 1);
            } else {
                lo = mid + 1;
                res = min(res, not_broken + 1);
            }
        }

        memo[K][N] = res;

        return res;
    }
};


#endif //CPP_887_2_H
