//
// Created by zhengxiaojian on 2021/1/7.
//

#ifndef CPP_685_H
#define CPP_685_H

#include <vector>

using namespace std;

struct UnionFind {
    vector<int> vertex;

    explicit UnionFind(int n) {
        vertex.resize(n);
        for (int i = 0; i < n; ++i) {
            vertex[i] = i;
        }
    }

    int find(int x) {
        if (x == vertex[x]) return x;
        return vertex[x] = find(vertex[x]);
    }

    void merge(int x, int y) {
        vertex[find(x)] = find(y);
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
        int nodesCount = edges.size();
        UnionFind uf(nodesCount + 1);
        auto parent = vector<int>(nodesCount + 1);
        for (int i = 1; i <= nodesCount; ++i) {
            parent[i] = i;
        }

        int conflict = -1;
        int cycle = -1;

        for (int i = 0; i < nodesCount; ++i) {
            auto &edge = edges[i];
            int node1 = edge[0], node2 = edge[1];

            if (parent[node2] != node2) {
                conflict = i;
            } else {
                parent[node2] = node1;
                if (uf.find(node1) == uf.find(node2)) {
                    cycle = i;
                } else {
                    uf.merge(node1, node2);
                }
            }
        }

        if (conflict < 0) {
            return edges[cycle];
        }

        auto conflictEdge = edges[conflict];
        if (cycle > 0) {
            return {parent[conflictEdge[1]], conflictEdge[1]};
        }
        return conflictEdge;
    }
};

#endif //CPP_685_H
