//
// Created by zhengxiaojian on 2021/1/9.
//

#ifndef CPP_1631_2_H
#define CPP_1631_2_H

#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int v;
    int w;
    int weight;
};

struct UnionFind {
    vector<int> parent;

    explicit UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }

    void merge(int x, int y) {
        parent[find(x)] = find(y);
    }

    bool isConnect(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>> &heights) {
        int n = heights.size(), m = heights[0].size();
        UnionFind unionFind(n * m);

        auto cmp = [](Edge &a, Edge &b) {
            return a.weight > b.weight;
        };
        priority_queue<Edge, vector<Edge>, decltype(cmp)> q(cmp);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int v = i * m + j;
                if (j + 1 < m) {
                    q.push({v, v + 1, abs(heights[i][j] - heights[i][j + 1])});
                }
                int w = (i + 1) * m + j;
                if (i + 1 < n) {
                    q.push({v, w, abs(heights[i][j] - heights[i + 1][j])});
                }
            }
        }

        int end = n * m - 1;
        int ans = 0;
        while (!unionFind.isConnect(0, end)) {
            auto &p = q.top();
            unionFind.merge(p.v, p.w);
            ans = p.weight;
            q.pop();
        }

        return ans;
    }
};

#endif //CPP_1631_2_H
