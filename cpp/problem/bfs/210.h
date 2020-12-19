//
// Created by zhengxiaojian on 2020/12/19.
//

#ifndef CPP_210_H
#define CPP_210_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> edges(numCourses);
        vector<int> in_degree(numCourses, 0);

        for (auto &p : prerequisites) {
            edges[p[1]].push_back(p[0]);
            in_degree[p[0]]++;
        }

        int handle = 0;
        vector<int> res;

        queue<int> q;

        for (int i = 0; i < numCourses; ++i) {
            if (in_degree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            ++handle;
            res.push_back(node);
            for (auto &p : edges[node]) {
                in_degree[p]--;
                if (in_degree[p] == 0) q.push(p);
            }
        }

        return handle == numCourses ? res : vector<int>();
    }
};

#endif //CPP_210_H
