//
// Created by zhengxiaojian on 2020/12/23.
//

#ifndef CPP_785_H
#define CPP_785_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>> &graph) {
        int n = graph.size();

        vector<int> color(n, 0);

        for (int i = 0; i < n; ++i) {
            if (color[i] != 0) continue;

            queue<int> q;
            q.push(i);
            color[i] = 1;

            while (!q.empty()) {
                int sz = q.size();

                for (int j = 0; j < sz; ++j) {
                    auto p = q.front();
                    q.pop();

                    for (auto next : graph[p]) {
                        if (color[next] == color[p]) return false;
                        if (color[next] == 0) {
                            color[next] = -color[p];
                            q.push(next);
                        }
                    }
                }
            }
        }

        return true;
    }
};

#endif //CPP_785_H
