//
// Created by zhengxiaojian on 2020/12/20.
//

#ifndef CPP_210_2_H
#define CPP_210_2_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> edges;
    vector<int> visit;
    bool valid = true;
    vector<int> res;

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        edges.resize(numCourses);
        visit.assign(numCourses, 0);

        for (const auto &p : prerequisites) {
            edges[p[1]].push_back(p[0]);
        }

        for (int i = 0; i < visit.size(); ++i) {
            if (visit[i] == 0) dfs(i);
        }

        reverse(res.begin(), res.end());

        return valid ? res : vector<int>();
    }

    void dfs(int vertex) {
        visit[vertex] = 1;
        for (const auto node : edges[vertex]) {
            if (visit[node] == 2) continue;
            if (visit[node] == 1) {
                valid = false;
                return;
            }
            dfs(node);
        }
        res.push_back(vertex);
        visit[vertex] = 2;
    }
};

#endif //CPP_210_2_H
