//
// Created by zhengxiaojian on 2020/12/10.
//

#ifndef CPP_514_H
#define CPP_514_H

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector <vector<int>> memo;

    int findRotateSteps(string ring, string key) {
        int r = ring.size();
        int k = key.size();
        memo.assign(r, vector(k, -1));
        return dfs(0, 0, ring, key);
    }

    int dfs(int r, int k, string &ring, string &key) {
        if (k == key.size()) return 0;

        if (memo[r][k] != -1) return memo[r][k];

        int ans = INT_MAX;
        int n = ring.size();
        for (int i = 0; i < n; ++i) {
            int next = (r + i) % n;
            if (ring[next] == key[k]) {
                ans = min(ans, dfs(next, k + 1, ring, key) + min(i, n - i) + 1);
            }
        }

        memo[r][k] = ans;
        return ans;
    }
};

#endif //CPP_514_H
