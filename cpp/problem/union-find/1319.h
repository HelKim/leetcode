//
// Created by zhengxiaojian on 2021/1/9.
//

#ifndef CPP_1319_H
#define CPP_1319_H

#include <vector>

using namespace std;

struct UnionFind {
    vector<int> parent;
    int count;

    explicit UnionFind(int n) {
        parent.resize(n);
        count = n;
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }

    void merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootY == rootX) return;

        parent[rootX] = rootY;
        --count;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>> &connections) {
        if (n - 1 > connections.size()) return -1;

        UnionFind unionFind(n);

        for (auto &connection : connections) {
            unionFind.merge(connection[0], connection[1]);
        }

        return unionFind.count - 1;
    }
};

#endif //CPP_1319_H
