//
// Created by zhengxiaojian on 2021/1/7.
//

#ifndef CPP_399_2_H
#define CPP_399_2_H

#include <vector>
#include <unordered_map>

using namespace std;

struct UnionFind {
    vector<int> parent;
    vector<double> weight;

    explicit UnionFind(int n) {
        parent.resize(n);
        weight.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            weight[i] = 1.0;
        }
    }

    int find(int x) {
        if (x == parent[x]) return x;

        int origin = parent[x];
        parent[x] = find(parent[x]);
        weight[x] *= weight[origin];
        return parent[x];
    }

    void merge(int x, int y, double value) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;
        parent[rootX] = rootY;
        weight[rootX] = weight[y] * value / weight[x];
    }

    double isConnected(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) {
            return weight[x] / weight[y];
        }
        return -1.0;
    }
};

class Solution {
public:
    vector<double>
    calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
        int equationsSize = equations.size();

        UnionFind unionFind(2 * equationsSize);
        unordered_map<string_view, int> map;
        int id = 0;

        for (int i = 0; i < equationsSize; ++i) {
            auto &equation = equations[i];
            string_view var1 = equation[0];
            string_view var2 = equation[1];

            if (!map.count(var1)) {
                map.insert({var1, id++});
            }
            if (!map.count(var2)) {
                map.insert({var2, id++});
            }
            unionFind.merge(map[var1], map[var2], values[i]);
        }

        int queriesSize = queries.size();
        vector<double> res(queriesSize);

        for (int i = 0; i < queriesSize; ++i) {
            string_view var1 = queries[i][0];
            string_view var2 = queries[i][1];

            if (!map.count(var1) || !map.count(var2)) {
                res[i] = -1;
            } else {
                res[i] = unionFind.isConnected(map[var1], map[var2]);
            }
        }

        return res;
    }
};

#endif //CPP_399_2_H
