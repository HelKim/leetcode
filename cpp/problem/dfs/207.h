//
// Created by zhengxiaojian on 2020/12/20.
//

#ifndef CPP_207_H
#define CPP_207_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> edges;
    vector<int> visit;
    bool valid = true;

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        edges.resize(numCourses);
        visit.assign(numCourses, 0);

        for (auto &p : prerequisites) {
            edges[p[0]].push_back(p[1]);
        }

        for (int i = 0; i < visit.size() && valid; ++i) {
            if (visit[i] == 0) dfs(i);
        }

        return valid;
    }

    void dfs(int vertex) {
        visit[vertex] = 1;
        for (auto node : edges[vertex]) {
            if (visit[node] == 2) continue;
            if (visit[node] == 1) {
                valid = false;
                return;
            }
            dfs(node);
        }
        visit[vertex] = 2;
    }
};

#endif //CPP_207_H
