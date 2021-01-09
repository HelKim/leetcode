//
// Created by zhengxiaojian on 2021/1/7.
//

#ifndef CPP_721_H
#define CPP_721_H

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct UnionFind {
    vector<int> parent;

    UnionFind() {
        parent.resize(10001);
        for (int i = 0; i <= 10000; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }

    void merge(int x, int y) {
        parent[find(x)] = find(y);
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        UnionFind unionFind;
        unordered_map<string_view, string_view> emailToName;
        unordered_map<string_view, int> emailToID;
        int id = 0;

        for (auto &account : accounts) {
            string_view name = account[0];
            for (int i = 1; i < account.size(); ++i) {
                emailToName.insert({account[i], name});
                if (!emailToID.count(account[i])) {
                    emailToID.insert({account[i], id++});
                }
                unionFind.merge(emailToID[account[1]], emailToID[account[i]]);
            }
        }

        unordered_map<int, vector<string_view>> ans;
        for (auto &item : emailToName) {
            int idx = unionFind.find(emailToID[item.first]);
            ans[idx].push_back(item.first);
        }
        auto cmp = [](string_view &a, string_view &b) {
            int i = 0, j = 0;
            while (i < a.size() && j < b.size()) {
                if (a[i] == b[j]) {
                    ++i;
                    ++j;
                    continue;
                }
                return a[i] < b[j];
            }
            return a.size() < b.size();
        };
        vector<vector<string>> res;
        for (auto &item : ans) {
            sort(item.second.begin(), item.second.end(), cmp);
            item.second.insert(item.second.begin(), emailToName[item.second[0]]);
            res.emplace_back(item.second.begin(), item.second.end());
        }

        return res;
    }
};

#endif //CPP_721_H
