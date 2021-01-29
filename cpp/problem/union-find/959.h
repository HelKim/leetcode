//
// Created by zhengxiaojian on 2021/1/25.
//

#ifndef CPP_959_H
#define CPP_959_H

#include <vector>
#include <string>

using namespace std;

struct UnionFind {
    vector<int> parent;
    int count;

    explicit UnionFind(int n) {
        count = n;
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }

    void merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry) return;
        --count;
        parent[rx] = ry;
    }
};

class Solution {
public:
    int regionsBySlashes(vector<string> &grid) {
        int n = grid.size();
        int size = 4 * n * n;
        UnionFind unionFind(size);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int idx = 4 * (i * n + j);
                char c = grid[i][j];

                if (c == '/') {
                    unionFind.merge(idx, idx + 3);
                    unionFind.merge(idx + 2, idx + 1);
                } else if (c == '\\') {
                    unionFind.merge(idx, idx + 1);
                    unionFind.merge(idx + 2, idx + 3);
                } else {
                    unionFind.merge(idx, idx + 1);
                    unionFind.merge(idx + 1, idx + 2);
                    unionFind.merge(idx + 2, idx + 3);
                }

                if (j + 1 < n) {
                    unionFind.merge(idx + 1, 4 * (i * n + j + 1) + 3);
                }

                if (i + 1 < n) {
                    unionFind.merge(idx + 2, 4 * ((i + 1) * n + j));
                }
            }
        }

        return unionFind.count;
    }
};

#endif //CPP_959_H
