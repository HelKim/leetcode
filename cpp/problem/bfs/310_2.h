//
// Created by zhengxiaojian on 2020/12/23.
//

#ifndef CPP_310_2_H
#define CPP_310_2_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        if (n == 1) return {0};

        vector<int> degree(n, 0);
        vector<vector<int>> _edges(n);

        for (const auto &e : edges) {
            degree[e[0]]++;
            degree[e[1]]++;
            _edges[e[0]].push_back(e[1]);
            _edges[e[1]].push_back(e[0]);
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) q.push(i);
        }

        vector<int> res;

        while (!q.empty()) {
            res.clear();

            int sz = q.size();

            for (int i = 0; i < sz; ++i) {
                auto p = q.front();
                q.pop();
                res.push_back(p);

                for (auto next : _edges[p]) {
                    degree[next]--;
                    if (degree[next] == 1) q.push(next);
                }
            }
        }

        return res;
    }
};

#endif //CPP_310_2_H
