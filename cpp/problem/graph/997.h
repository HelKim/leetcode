//
// Created by zhengxiaojian on 2021/1/7.
//

#ifndef CPP_997_H
#define CPP_997_H

#include <vector>

using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>> &trust) {
        vector<int> inDegree(N + 1, 0);
        vector<int> outDegree(N + 1, 0);

        for (auto &t : trust) {
            inDegree[t[1]]++;
            outDegree[t[0]]++;
        }

        for (int i = 1; i <= N; ++i) {
            if (inDegree[i] == N - 1 && outDegree[i] == 0) return i;
        }

        return -1;
    }
};

#endif //CPP_997_H
