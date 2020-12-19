//
// Created by zhengxiaojian on 2020/12/20.
//

#ifndef CPP_210_H
#define CPP_210_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> edges;
    vector<int> visit;
    vector<int> res;
    bool valid = true;

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        edges.resize(numCourses);
        visit.assign(numCourses, 0);

        for (auto &p : prerequisites) {
            edges[p[0]].push_back(p[1]);
        }

        for (int i = 0; i < visit.size(); ++i) {
            if (visit[i] == 0) dfs(i);
        }

        return valid ? res : vector<int>();
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
        res.push_back(vertex);
        visit[vertex] = 2;
    }
};

#endif //CPP_210_H
