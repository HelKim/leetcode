//
// Created by zhengxiaojian on 2021/1/11.
//

#ifndef CPP_1202_H
#define CPP_1202_H

#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <algorithm>

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
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return;
        --count;
        parent[rootX] = rootY;
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
        int n = s.size();

        UnionFind unionFind(n);
        for (auto &pair : pairs) {
            unionFind.merge(pair[0], pair[1]);
        }

        if (unionFind.count == 1) {
            sort(s.begin(), s.end());
            return s;
        }

        unordered_map<int, priority_queue<char, vector<char>, greater<>>> map;
        for (int i = 0; i < n; ++i) {
            map[unionFind.find(i)].push(s[i]);
        }

        for (int i = 0; i < n; ++i) {
            int root = unionFind.find(i);
            s[i] = map[root].top();
            map[root].pop();
        }

        return s;
    }
};

#endif //CPP_1202_H
