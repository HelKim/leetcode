//
// Created by zhengxiaojian on 2021/1/7.
//

#ifndef CPP_684_H
#define CPP_684_H

#include <vector>

using namespace std;

struct UnionFind {
    vector<int> vertex;
    vector<int> weight;

    UnionFind(int n) {
        vertex = vector(n, 0);
        weight = vector(n, 1);
        for (int i = 0; i < n; ++i) {
            vertex[i] = i;
        }
    }

    int find(int x) {
        if (x == vertex[x]) return x;

        return vertex[x] = find(vertex[x]);
    }

    bool merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return false;

        if (weight[rootX] > weight[rootY]) {
            vertex[rootY] = rootX;
            weight[rootX] += weight[rootY];
        } else {
            vertex[rootX] = rootY;
            weight[rootY] += weight[rootX];
        }

        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        int n = edges.size();
        UnionFind unionFind(2 * n);

        for (int i = 0; i < n; ++i) {
            auto &edge = edges[i];
            if (!unionFind.merge(edge[0], edge[1])) return edge;
        }

        return {};
    }
};

#endif //CPP_684_H
