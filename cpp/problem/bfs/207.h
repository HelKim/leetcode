//
// Created by zhengxiaojian on 2020/12/19.
//

#ifndef CPP_207_H
#define CPP_207_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> edges(numCourses);
        vector<int> in_degree(numCourses, 0);

        for (auto &p : prerequisites) {
            edges[p[1]].push_back(p[0]);
            in_degree[p[0]]++;
        }

        queue<int> q;

        for (int i = 0; i < in_degree.size(); ++i) {
            if (in_degree[i] == 0) q.push(i);
        }

        int handle = 0;

        while (!q.empty()) {
            int d = q.front();
            q.pop();
            ++handle;
            for (auto vertex : edges[d]) {
                in_degree[vertex]--;
                if (in_degree[vertex] == 0) q.push(vertex);
            }
        }

        return handle == numCourses;
    }
};

#endif //CPP_207_H
