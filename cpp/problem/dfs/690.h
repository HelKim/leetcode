//
// Created by zhengxiaojian on 2020/12/20.
//

#ifndef CPP_690_H
#define CPP_690_H

#include <vector>
#include <unordered_map>

using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    unordered_map<int, Employee *> map;

    int getImportance(vector<Employee *> employees, int id) {
        for (auto *e : employees) {
            map[e->id] = e;
        }

        return dfs(id);
    }

    int dfs(int id) {
        auto *e = map[id];

        int res = e->importance;

        for (auto it : e->subordinates) {
            res += dfs(it);
        }

        return res;
    }
};

#endif //CPP_690_H
