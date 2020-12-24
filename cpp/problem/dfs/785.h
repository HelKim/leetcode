//
// Created by zhengxiaojian on 2020/12/24.
//

#ifndef CPP_785_H
#define CPP_785_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> color;

    bool isBipartite(vector<vector<int>> &graph) {
        int n = graph.size();
        color.assign(n, 0);

        for (int i = 0; i < n; ++i) {
            if (color[i] == 0 && !dfs(i, 1, graph)) return false;
        }
        return true;
    }

    bool dfs(int node, int c, vector<vector<int>> &graph) {
        color[node] = c;

        for (auto next : graph[node]) {
            if (color[node] == color[next])
                return false;
            if (color[next] == 0 && !dfs(next, -c, graph)) {
                return false;
            }
        }

        return true;
    }
};

#endif //CPP_785_H
