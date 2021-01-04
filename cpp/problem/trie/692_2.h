//
// Created by zhengxiaojian on 2021/1/4.
//

#ifndef CPP_692_2_H
#define CPP_692_2_H

#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <list>

using namespace std;

bool operator<(const string &s1, const string &s2) {
    int i = 0, j = 0;
    while (i < s1.size() && j < s2.size()) {
        if (s1[i] == s2[i]) continue;
        return s1[i] < s2[i];
    }

    return s1.size() < s2.size();
}

class Solution {
public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        unordered_map<string, int> map;
        for (auto &w : words) {
            map[w]++;
        }

        auto cmp = [](pair<int, string_view> &a, pair<int, string_view> &b) {
            return a.first == b.first ? a.second < b.second : a.first > b.first;
        };
        priority_queue<pair<int, string_view>, vector<pair<int, string_view >>, decltype(cmp)> q(cmp);

        for (auto &iter : map) {
            if (k > q.size()) {
                q.push({iter.second, iter.first});
                continue;
            }
            if (iter.second > q.top().first || iter.second == q.top().first && iter.first < q.top().second) {
                q.pop();
                q.push({iter.second, iter.first});
            }
        }

        list<string_view> l;
        while (!q.empty()) {
            l.push_front(q.top().second);
            q.pop();
        }

        return vector<string>(l.begin(), l.end());
    }
};

#endif //CPP_692_2_H
