//
// Created by zhengxiaojian on 2021/1/9.
//

#ifndef CPP_1584_H
#define CPP_1584_H

#include <vector>
#include <queue>

using namespace std;

// Kruskal algorithm
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

    bool merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootY == rootX) return false;
        parent[rootX] = rootY;
        return true;
    }

};

struct Edge {
    int v;
    int w;
    int weight;

    Edge() = default;

    Edge(int v, int w, int weight) {
        this->v = v;
        this->w = w;
        this->weight = weight;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>> &points) {
        int n = points.size();
        UnionFind unionFind(n);

        auto cmp = [](Edge &a, Edge &b) {
            return a.weight > b.weight;
        };
        priority_queue<Edge, vector<Edge>, decltype(cmp)> q(cmp);

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                q.push({i, j, abs(points[i][0] - points[j][0]) +
                              abs(points[i][1] - points[j][1])});
            }
        }

        int add_edge_cnt = 0;
        int res = 0;
        while (add_edge_cnt < n - 1) {
            auto &e = q.top();
            if (unionFind.merge(e.w, e.v)) {
                res += e.weight;
                ++add_edge_cnt;
            }
            q.pop();
        }

        return res;
    }
};

#endif //CPP_1584_H
