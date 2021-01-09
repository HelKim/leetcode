//
// Created by zhengxiaojian on 2021/1/7.
//

#ifndef CPP_399_H
#define CPP_399_H

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    unordered_set<string_view> visit;
    unordered_map<string_view, vector<pair<string_view, double>>> edges;

    vector<double>
    calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {

        for (int i = 0; i < equations.size(); ++i) {
            auto &equation = equations[i];
            edges[equation[0]].push_back({equation[1], values[i]});
            edges[equation[1]].push_back({equation[0], 1 / values[i]});
        }

        vector<double> res;

        for (auto &query : queries) {
            if (!edges.count(query[0]) || !edges.count(query[1])) {
                res.push_back(-1);
                continue;
            }
            visit.clear();
            res.push_back(dfs(query[0], query[1]));
        }

        return res;
    }

    double dfs(string_view node, string_view target) {
        visit.insert(node);

        if (node == target) return 1;

        for (auto &edge : edges[node]) {
            if (visit.count(edge.first)) continue;
            double res = dfs(edge.first, target);
            if (res != -1) return res * edge.second;
        }

        return -1;
    }
};

#endif //CPP_399_H
