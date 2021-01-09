//
// Created by zhengxiaojian on 2021/1/8.
//

#ifndef CPP_947_H
#define CPP_947_H

#include <vector>
#include <unordered_map>

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

        if (rootX == rootY) return;

        parent[rootX] = rootY;
        --count;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>> &stones) {
        unordered_map<int, int> X, Y;
        UnionFind unionFind(stones.size());

        for (int i = 0; i < stones.size(); ++i) {
            auto &stone = stones[i];
            if (X.count(stone[0])) {
                unionFind.merge(i, X[stone[0]]);
            }
            X[stone[0]] = i;

            if (Y.count(stone[1])) {
                unionFind.merge(i, Y[stone[1]]);
            }
            Y[stone[1]] = i;
        }

        return stones.size() - unionFind.count;
    }
};

#endif //CPP_947_H
