//
// Created by zhengxiaojian on 2020/12/20.
//

#ifndef CPP_547_H
#define CPP_547_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> visit;

    int findCircleNum(vector<vector<int>> &M) {
        int n = M.size();
        if (n == 0) return 0;
        visit.assign(n, false);

        int r = 0;
        for (int i = 0; i < n; ++i) {
            if (!visit[i]) {
                dfs(i, M);
                ++r;
            }
        }

        return r;
    }

    void dfs(int v, vector<vector<int>> &M) {
        visit[v] = true;

        for (int i = 0; i < M.size(); ++i) {
            if (!visit[i] && M[v][i] == 1) dfs(i, M);
        }
    }
};

#endif //CPP_547_H
