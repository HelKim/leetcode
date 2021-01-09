//
// Created by zhengxiaojian on 2021/1/8.
//

#ifndef CPP_990_H
#define CPP_990_H

#include <vector>
#include <string>

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
        return x == vertex[x] ? x : vertex[x] = find(vertex[x]);
    }

    void merge(int x, int y) {
        vertex[find(x)] = find(y);
    }

    bool isConnect(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
public:
    bool equationsPossible(vector<string> &equations) {
        UnionFind unionFind(26);

        for (auto &equation : equations) {
            if (equation[1] == '=') {
                unionFind.merge(equation[0] - 'a', equation[3] - 'a');
            }
        }

        for (auto &equation: equations) {
            if (equation[1] == '!' && unionFind.isConnect(equation[0] - 'a', equation[3] - 'a'))
                return false;
        }

        return true;
    }
};

#endif //CPP_990_H
