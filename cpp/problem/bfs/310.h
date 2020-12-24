//
// Created by zhengxiaojian on 2020/12/23.
//

#ifndef CPP_310_H
#define CPP_310_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        vector<vector<int>> edges_(n);
        for (const auto &e: edges) {
            edges_[e[0]].push_back(e[1]);
            edges_[e[1]].push_back(e[0]);
        }

        vector<int> res;
        int mmin = INT_MAX;

        for (int i = 0; i < n; ++i) {
            queue<int> q;
            q.push(i);
            int level = -1;
            vector<bool> visit(n, false);
            while (!q.empty()) {
                ++level;
                int sz = q.size();

                for (int k = 0; k < sz; ++k) {
                    auto p = q.front();
                    visit[p] = true;
                    q.pop();

                    for (auto e : edges_[p]) {
                        if (visit[e]) continue;
                        q.push(e);
                    }
                }
            }

            if (level < mmin) {
                mmin = level;
                res = {i};
            } else if (level == mmin) {
                res.push_back(i);
            } else continue;
        }

        return res;
    }
};

#endif //CPP_310_H
