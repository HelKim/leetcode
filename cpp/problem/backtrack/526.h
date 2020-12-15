//
// Created by zhengxiaojian on 2020/12/15.
//

#ifndef CPP_526_H
#define CPP_526_H

#include <vector>

using namespace std;

class Solution {
public:
    int total = 0;
    vector<bool> visit = vector(10, false);

    int countArrangement(int N) {
        backtrack(1, N);
        return total;
    }

    void backtrack(int s, int N) {
        if (s > N) {
            ++total;
            return;
        }

        for (int i = 1; i <= N; ++i) {
            if (visit[i]) continue;
            if (i % s != 0 && s % i != 0) continue;
            visit[i] = true;
            backtrack(s + 1, N);
            visit[i] = false;
        }
    }
};

#endif //CPP_526_H
