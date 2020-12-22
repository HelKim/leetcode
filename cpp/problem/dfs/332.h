//
// Created by zhengxiaojian on 2020/12/20.
//

#ifndef CPP_332_H
#define CPP_332_H

#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<>>> vec;

    vector<string> stk;

    vector<string> findItinerary(vector<vector<string>> &tickets) {
        for (auto &it : tickets) {
            vec[it[0]].emplace(it[1]);
        }

        dfs("JFK");
        reverse(stk.begin(), stk.end());
        return stk;
    }

    void dfs(const string &curr) {
        while (vec.count(curr) && !vec[curr].empty()) {
            string tmp = vec[curr].top();
            vec[curr].pop();
            dfs(tmp);
        }
        stk.emplace_back(curr);
    }
};

#endif //CPP_332_H
