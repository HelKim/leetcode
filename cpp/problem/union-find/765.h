//
// Created by zhengxiaojian on 2021/2/19.
//

#ifndef CPP_765_H
#define CPP_765_H

#include <vector>

using namespace std;

struct UnionFind {
    vector<int> parent;
    int n;

    explicit UnionFind(int n) {
        this->n = n;
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void merge(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return;

        parent[px] = py;
        --n;
    }
};

class Solution {
public:
    int minSwapsCouples(vector<int> &row) {
        int n = row.size();
        UnionFind unionFind(n);

        for (int i = 0; i < n; i += 2) {
            unionFind.merge(i, i + 1);
            unionFind.merge(row[i], row[i + 1]);
        }

        return n / 2 - unionFind.n;
    }
};

#endif //CPP_765_H
