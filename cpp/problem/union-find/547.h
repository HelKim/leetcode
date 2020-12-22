//
// Created by zhengxiaojian on 2020/12/20.
//

#ifndef CPP_547_H
#define CPP_547_H

#include <vector>

using namespace std;

class UnionFind {
public:
    vector<int> vec;
    vector<int> sz;
    int count;

    explicit UnionFind(int n) {
        for (int i = 0; i < n; ++i) {
            vec.push_back(i);
            sz.push_back(1);
        }
        count = n;
    }

    int find(int p) {
        if (vec[p] == p) return p;
        return vec[p] = find(vec[p]);
    }

    void merge(int p, int q) {
        int i = find(p);
        int j = find(q);

        if (i == j) return;
        if (sz[i] < sz[j]) {
            vec[i] = j;
            sz[j] += sz[i];
        } else {
            vec[j] = i;
            sz[i] += sz[j];
        }
        count--;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>> &M) {
        int n = M.size();
        if (n == 0) return 0;

        UnionFind uf(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (M[i][j] == 1) {
                    uf.merge(i, j);
                }
            }
        }

        return uf.count;
    }
};

#endif //CPP_547_H
